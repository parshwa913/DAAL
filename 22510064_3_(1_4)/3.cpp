#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Point;

vector<Point> mergeSkylines(vector<Point>& leftSkyline, vector<Point>& rightSkyline) {
    vector<Point> mergedSkyline;
    int h1 = 0, h2 = 0, currentHeight = 0;
    int i = 0, j = 0;

    while (i < leftSkyline.size() && j < rightSkyline.size()) {
        int x1 = leftSkyline[i].first;
        int x2 = rightSkyline[j].first;
        int x;

        if (x1 < x2) {
            x = x1;
            h1 = leftSkyline[i].second;
            i++;
        } else if (x1 > x2) {
            x = x2;
            h2 = rightSkyline[j].second;
            j++;
        } else {
            x = x1;
            h1 = leftSkyline[i].second;
            h2 = rightSkyline[j].second;
            i++;
            j++;
        }

        int maxHeight = max(h1, h2);
        if (currentHeight != maxHeight) {
            mergedSkyline.push_back({x, maxHeight});
            currentHeight = maxHeight;
        }
    }

    while (i < leftSkyline.size()) {
        mergedSkyline.push_back(leftSkyline[i++]);
    }

    while (j < rightSkyline.size()) {
        mergedSkyline.push_back(rightSkyline[j++]);
    }

    return mergedSkyline;
}

vector<Point> skyline(vector<vector<int>>& buildings, int left, int right) {
    if (left == right) {
        return {{buildings[left][0], buildings[left][1]}, {buildings[left][2], 0}};
    }

    int mid = (left + right) / 2;
    vector<Point> leftSkyline = skyline(buildings, left, mid);
    vector<Point> rightSkyline = skyline(buildings, mid + 1, right);

    return mergeSkylines(leftSkyline, rightSkyline);
}

int main() {
    int n;
    cout << "Enter the number of buildings: ";
    cin >> n;
    
    vector<vector<int>> buildings(n, vector<int>(3));
    cout << "Enter the buildings in format (left ht right): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
    }
    
    vector<Point> result = skyline(buildings, 0, n - 1);
    
    cout << "The skyline is: ";
    for (auto p : result) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    
    return 0;
}
