class Solution {
public:

   int solve(int i, int n, unordered_map<int,vector<pair<int,int>>> &adj, int distanceThreshold){
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.push({0,i});

        vector<int> dist(n,INT_MAX);
        dist[i]=0;

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            int node = front.second;
            int nodeDist = front.first;

            if(nodeDist > dist[node]) continue;   

            for(auto &[nbr, wt] : adj[node]){
                int newDist = nodeDist + wt;
                if(newDist < dist[nbr]){
                    dist[nbr] = newDist;
                    pq.push({newDist,nbr});
                }
            }
        }

        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(j != i && dist[j] <= distanceThreshold)
                cnt++;
        }
        return cnt;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        int city = -1;
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt = solve(i,n,adj,distanceThreshold);
            if(cnt <= mn){
                mn = cnt;
                city = i;
            }
        }
        return city;
    }
};