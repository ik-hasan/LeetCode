// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int ans = 0;
//         vector<int> v(3,-1);
//         int r=0;
//         while(r<s.length()){
//             v[s[r]-'a'] = r;
//             if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){
//                 ans += 1 + min(v[0],min(v[1],v[2]));
//             }
//             r++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        unordered_map<char,int> mp;
        int r=0,l=0;
        while(r<s.length()){
            mp[s[r]]++;
            while(mp.size()==3){
                ans+=s.length()-r;
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};