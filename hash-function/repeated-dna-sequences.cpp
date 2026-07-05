class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        if(s.size()<10) return {};
        for(int i=0;i<=s.size()-10;i++){
            string s1 = s.substr(i,10);
            mp[s1]++;
        }

        vector<string> ans;
        for(auto &[str,freq]:mp){
            if(freq>1){
                ans.push_back(str);
            }
        }
        return ans;
    }
};