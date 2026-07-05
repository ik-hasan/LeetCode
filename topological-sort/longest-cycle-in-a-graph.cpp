class Solution {
public:

    void dfs(int src,vector<int>& edges,unordered_map<int,int>& visited,unordered_map<int,bool>& dfsTracker,int currentLength,int &cycleLength,vector<int>& dist){
        visited[src]=true;
        dfsTracker[src]=true;
        dist[src] = currentLength;
        int nextNode = edges[src];//bcz for al node there is only one nbr
        if(nextNode!=-1){
            if(!visited[nextNode]){
                dfs(nextNode,edges,visited,dfsTracker,currentLength+1,cycleLength,dist);
            }
            else if(visited[nextNode] && dfsTracker[nextNode]){
                int x = currentLength - dist[nextNode] + 1;
                cycleLength = max(x,cycleLength);
            }
        }

        dfsTracker[src]=false;
    }
    int longestCycle(vector<int>& edges) {
        int cycleLength = -1;
        unordered_map<int,int> visited;
        unordered_map<int,bool> dfsTracker;
        int n = edges.size();
        vector<int> dist(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges,visited,dfsTracker,0,cycleLength,dist);
            }
        }
        return cycleLength;
    }
};