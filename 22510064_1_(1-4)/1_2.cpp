#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


void sortAnagrams(vector<string>& strings) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& str : strings) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }

    int index = 0;
    for (const auto& pair : anagramGroups) {
        for (const string& str : pair.second) {
            strings[index++] = str;
        }
    }
}

int main() {
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;

    vector<string> strings(numStrings);
    cout << "Enter the strings: ";
    for (int i = 0; i < numStrings; ++i) {
        cin >> strings[i];
    }

    sortAnagrams(strings);

    cout << "Strings grouped by anagrams: ";
    for (const string& str : strings) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
