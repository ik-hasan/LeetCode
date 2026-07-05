// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.size()==0) return 0;
//         int l=0,ans=INT_MIN;
//         unordered_map<char,int> mp;

//         for(int r=0;r<s.length();r++){
//             mp[s[r]]++;
//             while(mp[s[r]]>1){
//                 mp[s[l]]--;
//                 if(mp[s[l]]==0) mp.erase(s[l]);
//                 l++;
//             }
//             ans = max(ans,r-l+1);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int l=0,ans=INT_MIN;
        unordered_map<char,int> mp;

        for(int r=0;r<s.length();r++){
            if(mp.find(s[r])!=mp.end()){
                l = max(l, mp[s[r]] + 1);
            }
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};