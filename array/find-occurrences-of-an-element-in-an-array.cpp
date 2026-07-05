class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        unordered_map<int,vector<int>> mp;
        for(auto int i=0;i<nums.size();i++){
            if(nums[i]==x){
                mp[x].push_back(i);
            }
        }
        vector<int> ans;
        int j=0;
        for(auto it:q){
            if(it>mp[x].size()) ans.push_back(-1);
            else ans.push_back(mp[x][it-1]);
        }
        return ans;
    }
};