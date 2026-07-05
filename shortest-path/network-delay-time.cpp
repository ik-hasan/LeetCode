class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it:t){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        while(!pq.empty()){
            auto front = pq.top();
            int nodeDist = front.first;
            int node = front.second;
            pq.pop();

            for(auto nbr : adj[node]){
                int nbrWt = nbr.second;
                int nbrNode = nbr.first;
                int nbrDist = dist[nbrNode];
                int newDist = nbrWt + nodeDist;

                if(nbrDist > newDist){
                    dist[nbrNode] = newDist;
                    pq.push({dist[nbrNode],nbrNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<n+1;i++){
            ans = max(ans,dist[i]);
        }
        return (ans==INT_MAX ? -1 : ans);
    }
};