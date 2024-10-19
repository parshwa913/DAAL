//Modified dijkstra-->Bellman-Ford
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool bellmanFord(int V, int E, vector<vector<int>> &edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle.\n";
            return false;
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\t\t" << "INF" << endl;
        } else {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
    return true;
}

int main() {
    int V, E, source;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter each edge (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter source vertex: ";
    cin >> source;

    bool noNegativeCycle = bellmanFord(V, E, edges, source);
    if (noNegativeCycle) {
        cout << "Shortest path calculated successfully.\n";
    } else {
        cout << "Failed due to negative weight cycle.\n";
    }
    return 0;
}
