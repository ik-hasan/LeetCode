class Solution {
public:

    void dfs(int root,unordered_map<int,bool> &vis, unordered_map<int,vector<int>> &adj){
            
        for(auto &nbr:adj[root]){
            if(!vis[nbr]) {
                vis[nbr]=true;
                dfs(nbr,vis,adj);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& m) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        unordered_map<int,bool> vis;
        for(int i=0;i<m.size();i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};