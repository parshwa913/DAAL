#include <iostream>
#include <vector>
#include <string>
using namespace std;


int findStringWithEmpty(const vector<string>& strings, const string& target) {
    int left = 0, right = strings.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int midLeft = mid, midRight = mid;
        while (midLeft >= left && strings[midLeft].empty()) --midLeft;
        while (midRight <= right && strings[midRight].empty()) ++midRight;

        if (midLeft < left && midRight > right) {
            return -1; 
        }

        mid = (midLeft >= left) ? midLeft : midRight;

        if (strings[mid] == target) {
            return mid;
        } else if (strings[mid] < target) {
            left = midRight + 1;
        } else {
            right = midLeft - 1;
        }
    }

    return -1;  
}

int main() {
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;

    vector<string> strings(numStrings);
    cout << "Enter the strings (use empty strings as needed): ";
    for (int i = 0; i < numStrings; ++i) {
        cin >> strings[i];
    }

    string target;
    cout << "Enter the target string to find: ";
    cin >> target;

    int index = findStringWithEmpty(strings, target);

    if (index != -1) {
        cout << "String found at index: " << index << endl;
    } else {
        cout << "String not found in the array." << endl;
    }

    return 0;
}
