#include <iostream>
#include <vector>
using namespace std;
void mergeSortedArrays(vector<int>& A, vector<int>& B) {
    int lastA = A.size() - B.size() - 1; 
    int lastB = B.size() - 1;            
    int last = A.size() - 1;              

    while (lastB >= 0) {
        if (lastA >= 0 && A[lastA] > B[lastB]) {
            A[last] = A[lastA];
            lastA--;
        } else {
            A[last] = B[lastB];
            lastB--;
        }
        last--;
    }
}

int main() {
    int sizeA, sizeB, input;
    cout << "Enter the number of elements in array A (including buffer): ";
    cin >> sizeA;
    cout << "Enter the number of elements in array B: ";
    cin >> sizeB;

    vector<int> A(sizeA, 0);
    vector<int> B(sizeB, 0);

    cout << "Enter elements of array A (excluding buffer, sorted): ";
    for (int i = 0; i < sizeA - sizeB; ++i) {
        cin >> A[i];
    }

    cout << "Enter elements of array B (sorted): ";
    for (int i = 0; i < sizeB; ++i) {
        cin >> B[i];
    }

    mergeSortedArrays(A, B);

    cout << "Merged array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
