
//agr graph cyclic hua to topo sort using bfs  kuch nodes ko traverse nhi kr paega 
//bcz kuch nodes ki indegree 0 nhi hogi but topoSort using dfs ke sath aisa nhi h 
//agr graph cyclic hua tb bhi ye saare nodes ko traverse kr lega
//isliye is problem ko sirf topoSort using DFS se nhi kiya ja skta jbki topoSort using bfs se kiya ja skta h.
class Solution {
public:
    bool topoSort(int n,vector<int>& ans,unordered_map<int,list<int>> &adjList){

        unordered_map<int,int>indegree;

        for(int i=0;i<n;i++){
            for(auto x:adjList[i]){
                indegree[x]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto nbr: adjList[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0) {
                    q.push(nbr);
                }
            }
        }

        if(ans.size()==n) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) return true;

        unordered_map<int,list<int>> adjList;

        for(auto x:prerequisites){
            int u = x[0];
            int v = x[1];
            adjList[u].push_back(v);
        }

        vector<int> ans;
        if(topoSort(numCourses,ans,adjList)) return true;
        return false;
    }
};



//soln-2 dfs cycle detection
// class Solution {
// public:

//     bool dfs(int src, unordered_map<int,bool> &dfsTracker,
//              unordered_map<int,bool> &visited,
//              unordered_map<int,list<int>> &adjList){

//         visited[src] = true;
//         dfsTracker[src] = true;

//         for(auto nbr : adjList[src]){
//             if(!visited[nbr]){
//                 if(dfs(nbr, dfsTracker, visited, adjList)) return true;
//             }
//             else if(visited[nbr] && dfsTracker[nbr]){
//                 return true; // cycle found
//             }
//         }

//         dfsTracker[src] = false;
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         if(prerequisites.size()==0) return true;

//         unordered_map<int,list<int>> adjList;

//         for(auto x:prerequisites){
//             int u = x[0];
//             int v = x[1];
//             adjList[u].push_back(v);
//         }

//         unordered_map<int,bool> dfsTracker;
//         unordered_map<int,bool> visited;
//         for(int i=0;i<numCourses;i++){
//             if(!visited[i]){
//                 if(dfs(i,dfsTracker,visited,adjList)) return false;
//             }
//         }
//         return true;

//     }
// };




