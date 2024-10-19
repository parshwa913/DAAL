#include <iostream>
#include <vector>
using namespace std;
int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

vector<int> getArrayInput(int N) {
    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    return arr;
}

int main() {
    int N, target;
    cout << "Enter the number of elements: ";
    cin >> N;
    
    vector<int> arr = getArrayInput(N);
    
    cout << "Enter the target element: ";
    cin >> target;
    
    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
