class Solution {
public:
    vector<int> dup(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        nums.resize(j+1);
        return nums;
    }
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/3){
                ans.push_back(nums[i]);
            }
        }
        if(ans.size()==0){
            // ans.push_back(0);
            return ans;
        }
        sort(ans.begin(),ans.end());
        return dup(ans);
    }
};