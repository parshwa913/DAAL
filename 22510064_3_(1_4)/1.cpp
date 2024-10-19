#include <iostream>
using namespace std;

int findMaximum(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (mid > 0 && mid < n - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return arr[mid];
            } else if (arr[mid - 1] > arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (mid == 0) {
            return max(arr[0], arr[1]);
        } else if (mid == n - 1) {
            return max(arr[n - 1], arr[n - 2]);
        }
    }
    
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int maxElement = findMaximum(arr, n);
    cout << "The maximum element in the bitonic array is: " << maxElement << endl;
    
    return 0;
}
