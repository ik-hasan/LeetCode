class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char,int> mp;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end() && i-mp[s[i]]<=k){
                s.erase(i,1);
                i--;
                continue;
            }
            else {
                ans.push_back(s[i]);
            }
            mp[s[i]]=i;
        }
        return ans;


    }
};