// class Solution {
// public:

//     void dfsTerminal(int src,unordered_map<int,list<int>> &adjList,unordered_map<int,bool>& visited,vector<int> &terminal){

//         visited[src]=true;
//         if(adjList[src].empty()){
//             terminal.push_back(src);
//             return;
//         }
//         for(auto nbr : adjList[src]){
//             if(!visited[nbr]){
//                 dfsTerminal(nbr,adjList,visited,terminal);
//             }
//         }
//         return;
//     }

//     void bfsSafeNode(int src,unordered_map<int,list<int>> &adjList,vector<int> &terminal,vector<int> & safeNode){

//         auto x = find(terminal.begin(),terminal.end(),src);
//         if(x != terminal.end()) return;

//         bool flag = true;
//         for(auto nbr : adjList[src]){
//             auto it = find(terminal.begin(),terminal.end(),nbr);
//             if(it == terminal.end()){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag) safeNode.push_back(src);
//         return;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
//         unordered_map<int,list<int>> adjList;

//         for(int i =0;i<graph.size();i++){
//             for(auto nbr : graph[i])
//                 adjList[i].push_back(nbr);
//         }
//         // adjList ready

//         unordered_map<int,bool> visited;
//         vector<int> terminal;
//         vector<int> safeNode;

//         for(int i=0;i<graph.size();i++){
//             if(!visited[i]){
//                 dfsTerminal(i,adjList,visited,terminal);
//             }
//         }
//         //terminal array ready

//         for(int i=0;i<graph.size();i++){
//             bfsSafeNode(i,adjList,terminal,safeNode);
//         }
//         //safeNode array ready

//         vector<int> ans ;
//         for(int i = 0;i<terminal.size();i++){
//             ans.push_back(terminal[i]);
//         }
//         for(int i = 0;i<safeNode.size();i++){
//             ans.push_back(safeNode[i]);
//         }
//         sort(ans.begin(),ans.end());

//         return ans;

//     }
// };

class Solution {
public:
    void dfsTerminal(int src, unordered_map<int,list<int>> &adjList,unordered_map<int,bool>& visited, vector<bool> &isSafe) {
        visited[src] = true;
        if(adjList[src].empty()) {
            isSafe[src] = true;  // terminal = safe
            return;
        }
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                dfsTerminal(nbr, adjList, visited, isSafe);
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,list<int>> adjList;
        for(int i = 0; i < n; i++)
            for(auto nbr : graph[i])
                adjList[i].push_back(nbr);

        unordered_map<int,bool> visited;
        vector<bool> isSafe(n, false);

        // Step 1: terminal nodes mark karo
        for(int i = 0; i < n; i++){
            if(!visited[i]) dfsTerminal(i, adjList, visited, isSafe);
        }

        // Step 2: iteratively safe propagate karo
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < n; i++) {
                if(isSafe[i]) continue;  
                
                bool allSafe = true;
                for(auto nbr : adjList[i]) {
                    if(!isSafe[nbr]) {
                        allSafe = false;
                        break;
                    }
                }
                if(allSafe && !adjList[i].empty()) { 
                    isSafe[i] = true;
                    changed = true;
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++)
            if(isSafe[i]) result.push_back(i);

        return result;
    }
};
