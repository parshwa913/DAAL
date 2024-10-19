#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>  
using namespace std;

void splitAndSortChunks(const string& inputFile, const string& tempFilePrefix, int chunkSize) {
    ifstream input(inputFile);
    string line;
    int chunkNumber = 0;

    while (!input.eof()) {
        vector<string> lines;
        lines.reserve(chunkSize);

        for (int i = 0; i < chunkSize && getline(input, line); ++i) {
            lines.push_back(line);
        }

        sort(lines.begin(), lines.end());

        ofstream tempFile(tempFilePrefix + to_string(chunkNumber++) + ".txt");
        for (const string& sortedLine : lines) {
            tempFile << sortedLine << '\n';
        }
        tempFile.close();
    }

    input.close();
}

void mergeChunks(const string& tempFilePrefix, int numChunks, const string& outputFile) {
    ofstream output(outputFile);
    vector<ifstream> tempFiles(numChunks);

    auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first > b.first;  
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> minHeap(cmp);

    for (int i = 0; i < numChunks; ++i) {
        tempFiles[i].open(tempFilePrefix + to_string(i) + ".txt");
        string line;
        if (getline(tempFiles[i], line)) {
            minHeap.push(make_pair(line, i));
        }
    }

    while (!minHeap.empty()) {
        pair<string, int> smallestPair = minHeap.top();
        minHeap.pop();
        
        string smallest = smallestPair.first;
        int fileIndex = smallestPair.second;

        output << smallest << '\n';

        string nextLine;
        if (getline(tempFiles[fileIndex], nextLine)) {
            minHeap.push(make_pair(nextLine, fileIndex));
        }
    }

    output.close();

    for (int i = 0; i < numChunks; ++i) {
        tempFiles[i].close();
    }
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    string tempFilePrefix = "temp_chunk_";
    int chunkSize = 3; 

    splitAndSortChunks(inputFile, tempFilePrefix, chunkSize);
    
    int numChunks = 4; 
    mergeChunks(tempFilePrefix, numChunks, outputFile);

    cout << "File sorted successfully. Check the output file: " << outputFile << endl;
    return 0;
}
