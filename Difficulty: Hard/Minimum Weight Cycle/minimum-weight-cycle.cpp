//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        const int INF = 1e9;
        vector<vector<int>> dist(V, vector<int>(V, INF));
        vector<vector<int>> graph(V, vector<int>(V, INF));

        // Initialize graph with given edge weights
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u][v] = w;
            graph[v][u] = w;
            dist[u][v] = w;
            dist[v][u] = w;
        }

        int minCycle = INF;

        // Floyd-Warshall Algorithm with cycle check
        for (int k = 0; k < V; ++k) {
            // Check for cycles before updating dist[][] using vertex k
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (i != j && graph[i][k] != INF && graph[k][j] != INF && dist[i][j] != INF) {
                        int cycleWeight = dist[i][j] + graph[i][k] + graph[k][j];
                        minCycle = min(minCycle, cycleWeight);
                    }
                }
            }

            // Now update shortest distances with k as intermediate
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return (minCycle == INF) ? -1 : minCycle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends