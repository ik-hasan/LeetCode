class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>> adjList;
        vector<int> dist(n,INT_MAX);

        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,2*wt});
        }

        set<pair<int,int>> st;
        dist[0]=0;
        st.insert({0,0});//{distance,node}

        while(!st.empty()){
            auto front = *(st.begin());
            int srcDist = front.first;
            int src = front.second;
            st.erase(front);

            if(src == n-1) return srcDist;

            for(auto nbr : adjList[src]){

                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(dist[src] + nbrDist < dist[nbrNode]){
                    //delete this entry from set & insert newOne with updated distance
                    auto result = st.find({dist[nbrNode],nbrNode});
                    if(result != st.end()){
                        st.erase(result);
                    }
                    dist[nbrNode] = dist[src]+nbrDist;
                    st.insert({dist[nbrNode],nbrNode});
                }

            }
        }
        return -1;
        
    }
};