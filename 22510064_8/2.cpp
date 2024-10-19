#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

pair<int, int> minElevatorRides(int n, int x, const vector<int>& weights) {
    int totalMasks = 1 << n;
    vector<pair<int, int>> dp(totalMasks, {n + 1, 0});
    dp[0] = {1, 0};

    for (int mask = 1; mask < totalMasks; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                int prevMask = mask ^ (1 << i);
                pair<int, int> option = dp[prevMask];
                if (option.second + weights[i] <= x) {
                    option.second += weights[i];
                } else {
                    option.first += 1;
                    option.second = weights[i];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    return dp[totalMasks - 1];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    pair<int, int> result = minElevatorRides(n, x, weights);
    cout << result.first << endl;
    return 0;
}
