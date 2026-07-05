class Solution {
public:
    bool solve(vector<vector<int>>& graph,int node,vector<int> &color,int col){
        color[node] = col;
        for(auto nbr:graph[node]){
            if(color[nbr]==col) return false;
            else if(color[nbr]==-1){
                if(!solve(graph,nbr,color,1-col)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!solve(graph,i,color,1)) return false;
            }
        }
        return true;
    }
};