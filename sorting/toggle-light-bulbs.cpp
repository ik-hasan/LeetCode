class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> mp;
        for(auto x:bulbs) mp[x]++;
        vector<int> ans;
        for(auto &x:mp){
            if(x.second %2 !=0) ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};