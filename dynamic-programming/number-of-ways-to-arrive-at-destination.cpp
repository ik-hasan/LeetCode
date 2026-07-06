class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [nodeDist, node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (nodeDist > dist[node])
                continue;

            for (auto &[nbr, wt] : adj[node]) {

                long long newDist = nodeDist + wt;

                // Better shortest distance found
                if (newDist < dist[nbr]) {
                    dist[nbr] = newDist;
                    ways[nbr] = ways[node];
                    pq.push({newDist, nbr});
                }

                // Another shortest path found
                else if (newDist == dist[nbr]) {
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};