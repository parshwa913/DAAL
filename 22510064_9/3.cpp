#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumTimeForHandshakes(int N, vector<vector<int>>& preferences) {
    vector<vector<int>> adj(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < preferences[i].size() - 1; j++) {
            int u = preferences[i][j];
            int v = preferences[i][j + 1];
            adj[u].push_back(v);
            indegree[v]++;
        }
    }

    queue<int> q;
    vector<int> topological_order;
    vector<int> level(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            level[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topological_order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }

    if (topological_order.size() != N) {
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                level[i] = 1;
                break;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topological_order.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    level[v] = level[u] + 1;
                }
            }
        }
    }

    int max_level = 0;
    for (int i = 1; i <= N; i++) {
        max_level = max(max_level, level[i]);
    }

    return max_level * 3;
}

int main() {
    int N;
    cout << "Enter the number of guests: ";
    cin >> N;

    vector<vector<int>> preferences(N);
    
    cout << "Enter the handshake sequence for each guest:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            int guest;
            cin >> guest;
            preferences[i].push_back(guest);
        }
    }

    int result = minimumTimeForHandshakes(N, preferences);

    if (result == 0) {
        cout << "Inconsistent handshake data\n";
    } else {
        cout << "Minimum time required: " << result << " seconds\n";
    }

    return 0;
}