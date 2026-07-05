// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

//         unordered_map<int,list<pair<int,int>>> adjList;
//         for(auto u:flights){
//             adjList[u[0]].push_back({u[1],u[2]});
//         }
//         set<tuple<int,int,int>> st;  //cost,city,stops
//         st.insert({0,src,0});

//         while(!st.empty()){
//             auto [cost, city, stops] = *st.begin();
//             st.erase(st.begin());
//             if( city==dst ) return cost;
//             if(stops > k) continue;

//             for(auto nbr : adjList[city]){
//                 int newCity = nbr.first;
//                 int newWt = nbr.second;
//                 st.insert({cost+newWt,newCity,stops+1});
//             }
//         }
//         return -1;
//     }
// };


//more optimize
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,list<pair<int,int>>> adjList;
        for(auto u:flights){
            adjList[u[0]].push_back({u[1],u[2]});
        }
        set<tuple<int,int,int>> st;  //cost,city,stops
        st.insert({0,src,0});
        vector<int> visited(n,INT_MAX);//agr hm kisi city pr phle hi less number of stops se phoch chuke to continue
        visited[src]=0;

        while(!st.empty()){
            auto [cost, city, stops] = *st.begin();
            st.erase(st.begin());
            if( city==dst ) return cost;
            if(stops > k) continue;

            if(visited[city]<stops) continue;
            visited[city]= min(visited[city],stops);

            for(auto nbr : adjList[city]){
                int newCity = nbr.first;
                int newWt = nbr.second;
                st.insert({cost+newWt,newCity,stops+1});
            }
        }
        return -1;
    }
};
