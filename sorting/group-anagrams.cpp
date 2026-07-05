//TLE SOLN, BUT WITH KEY OBSERVATION OF EDGE CASES GOOD FOR INTERVIEW BUT NOT FOR OA
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
//         unordered_map<char,int> mp;
//         vector<vector<string>> ans;
//         unordered_map<string,bool> vis;

//         for(int i=0;i<strs.size();i++){
//             string s1 = strs[i];
//             if(vis[s1])continue;
//             vector<string> temp;
//             temp.push_back(s1);
//             vis[s1]=true;
//             for(auto x:s1){
//                 mp[x]++;
//             }

//             for(int j=i+1;j<strs.size();j++){
//                 string s2 = strs[j];
//                 if(s1=="" && s2=="") {
//                     temp.push_back(s2);
//                     continue;
//                 }
//                 bool isAdd = true;
//                 bool check = false;
//                 unordered_map<char,int> mpp = mp;
//                 for(auto y : s2){
//                     check=true;
//                     mpp[y]--;
//                 }
//                 for(auto x : mpp){
//                     if(x.second > 0 || x.second<0) isAdd = false;
//                 }
//                 mpp.clear();
//                 if(isAdd && check) {
//                     vis[s2] = true;
//                     temp.push_back(s2);
//                 }
//             }

//             ans.push_back(temp);
//             mp.clear();
//         } 

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;

        for(auto it:strs){
            string s = it;
            sort(s.begin(),s.end());
            mp[s].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};