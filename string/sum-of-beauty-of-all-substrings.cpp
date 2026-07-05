// class Solution {
// public:
//     int ans = 0;
//     int check(string s){
//         unordered_map<char,int> mp;
//         for(auto it:s){
//             mp[it]++;
//         }
//         int mn = INT_MAX;
//         int mx = INT_MIN;
//         for(auto it:mp){
//             mn = min(mn,it.second);
//             mx = max(mx,it.second);
//         }
//         return mx - mn;
//     }
//     int solve(string &s,int index){
//         if(index > s.size()) return ans;
//         for(int i = 0; i + index <= s.size(); i++){
//             string newS = s.substr(i,index);
//             ans += check(newS);
//         }
//         return solve(s,index+1);
//     }

//     int beautySum(string s) {
//         solve(s,1);
//         return ans;
//     }
// };

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            vector<int> freq(26,0);
            for(int j = i; j < s.size(); j++){
                freq[s[j]-'a']++;
                int mx = 0;
                int mn = INT_MAX;
                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};