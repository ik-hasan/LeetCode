class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj,
             vector<bool>& vis, int &nodes, int &edges) {
        vis[node] = true;
        nodes++;
        edges += adj[node].size();   // degree add karo
        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int totalDegree = 0;
                dfs(i, adj, vis, nodes, totalDegree);
                int totalEdges = totalDegree / 2;
                if (totalEdges == (nodes * (nodes - 1)) / 2)
                    ans++;
            }
        }
        return ans;
    }
};