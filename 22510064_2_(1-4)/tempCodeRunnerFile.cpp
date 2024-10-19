#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

std::vector<int> getSortedArrayInput(int N) {
    std::vector<int> arr(N);
    std::cout << "Enter the sorted elements: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}

int main() {
    int N, target;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;
    
    std::vector<int> arr = getSortedArrayInput(N);
    
    std::cout << "Enter the target element: ";
    std::cin >> target;
    
    int index = binarySearch(arr, target);
    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    
    return 0;
}
