#include <iostream>
#include <cmath>
using namespace std;

int max_separations(int arr[], int N, int K) {
    int odd_count = 0, even_count = 0, separations = 0, cost = 0;
    
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
        
        if (odd_count == even_count) {
            cost += abs(arr[i] - arr[i + 1]);
            if (cost <= K) {
                separations++;
            } else {
                break;
            }
        }
    }
    return separations;
}

int main() {
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << "Max Separations: " << max_separations(arr, N, K) << endl;
    return 0;
}
