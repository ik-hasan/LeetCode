class Solution {
public:
    vector<int> topoSort(int n,unordered_map<int,list<int>> &adjList){

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
        vector<int> ans;

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
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,list<int>> adjList;

        for(auto x:prerequisites){
            int u = x[0];
            int v = x[1];
            adjList[u].push_back(v);
        }

        auto ans = topoSort(numCourses,adjList);
        if(ans.size()!=numCourses) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};