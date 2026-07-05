// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {

//         sort(intervals.begin(),intervals.end());
//         set<pair<int,int>> st;
//         for(auto it:intervals){
//             int elem = it[0];
//             bool flag = true;
//             for(auto it2:st){
//                 int first = it2.first;
//                 int sec = it2.second;
//                 if(elem >= first && elem <= sec){
//                     int maxi = max(it[1],sec);
//                     st.erase({first,sec});
//                     st.insert({first,maxi});
//                     flag = false;
//                 }
//             }
//             if(flag) st.insert({it[0],it[1]});
//         }
        
//         vector<vector<int>> ans;
//         for(auto it:st){
//             ans.push_back({it.first,it.second});
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto it:intervals){
            
            if(ans.empty() || ans.back()[1] < it[0]){
                ans.push_back(it);
            }
            else {
                ans.back()[1] = max(ans.back()[1],it[1]);
            }
        }
        return ans;
    }
};