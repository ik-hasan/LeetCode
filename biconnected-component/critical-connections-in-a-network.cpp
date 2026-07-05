class Solution {
public:
    void countBridges(int src,int parent,int timer,vector<int>& low,vector<int>& tin,
    unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adjList,vector<vector<int>>& ans){

        timer++;
        visited[src]=true;
        low[src] = timer;
        tin[src] = timer;

        for(auto nbr : adjList[src]){
            if(nbr==parent){
                continue;
            }
            else if(!visited[nbr]){
                //normal traversal kro & check for bridges wapas aane pr
                countBridges(nbr,src,timer,low,tin,visited,adjList,ans);
                //ab mai wapas aaya hu ab bridges ke liye check krunga
                low[src] = min(low[src],low[nbr]);
                if(low[nbr] > tin[src]){
                    ans.push_back({src,nbr});
                }
            }
            else{
                //already visited and not parent
                low[src]=min(low[src],low[nbr]);
            }
        }
    }

    //ye question tarzan algo ka h, (critical server = bridge)
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        unordered_map<int,list<int>> adjList;
        for(auto x : connections){
            int u = x[0];
            int v = x[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int src = 0;
        int timer = 0;
        int parent = -1;
        vector<int> tin(n);//insertion time
        vector<int> low(n);//lowest time
        unordered_map<int,bool> visited;

        vector<vector<int>> ans;
        countBridges(src,parent,timer,low,tin,visited,adjList,ans);

        return ans;
    }
};