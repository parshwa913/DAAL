#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longest_subarray_with_conditions(const vector<int>& A, int N, int X, int Y) {
    unordered_map<int, int> freq_map;
    int left = 0, max_len = 0, distinct_count = 0;
    bool y_present = false;

    for (int right = 0; right < N; ++right) {
        if (freq_map[A[right]] == 0)
            distinct_count++;
        freq_map[A[right]]++;
        
        if (A[right] == Y)
            y_present = true;
        
        while (distinct_count > X) {
            freq_map[A[left]]--;
            if (freq_map[A[left]] == 0)
                distinct_count--;
            if (A[left] == Y)
                y_present = false;
            left++;
        }
        
        if (distinct_count == X && y_present)
            max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> A(N);
        
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        
        cout << longest_subarray_with_conditions(A, N, X, Y) << endl;
    }
    
    return 0;
}
