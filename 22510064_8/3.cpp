#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxScore(const vector<vector<int>>& grid, int N) {
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        if (i > 1) {
            dp[i] = max(dp[i], dp[i-2] + abs(grid[0][i-1] - grid[0][i-2]) + abs(grid[1][i-1] - grid[1][i-2]));
        }
        dp[i] = max(dp[i], dp[i-1] + abs(grid[0][i-1] - grid[1][i-1]));
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(2, vector<int>(N));
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << maxScore(grid, N) << endl;
    return 0;
}
