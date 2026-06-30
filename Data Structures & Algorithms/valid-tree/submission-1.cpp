class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Check 1: edge count must be exactly n-1
        if (edges.size() != n - 1) return false;

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS from node 0
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int visitedCount = 1;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    visitedCount++;
                    q.push(next);
                }
            }
        }

        // Check 2: all n nodes must be reachable from node 0
        return visitedCount == n;
    }
};