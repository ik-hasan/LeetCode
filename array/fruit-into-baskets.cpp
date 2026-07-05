// class Solution {
// public:
//     int totalFruit(vector<int>& f) {
//         int l=0,ans = INT_MIN;
//         unordered_map<int,int> mp;
//         for(int r=0;r<f.size();r++){
//             mp[f[r]]++;
//             while(mp.size()>2){
//                 mp[f[l]]--;
//                 if(mp[f[l]]==0) mp.erase(f[l]);
//                 l++;
//             }
//             ans = max(ans,r-l+1);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int totalFruit(vector<int>& f) {
        int l=0,ans = INT_MIN;
        unordered_map<int,int> mp;
        for(int r=0;r<f.size();r++){
            mp[f[r]]++;
            if(mp.size()>2){
                mp[f[l]]--;
                if(mp[f[l]]==0) mp.erase(f[l]);
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};