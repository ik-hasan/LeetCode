class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;

        int n = nums[nums.size()-1] - nums[0] + 1;

        for(int i = 0;i<n-1;i++){
            if(nums[i+1]!=nums[i]+1) {
                ans.push_back(nums[i]+1);
                nums.insert(nums.begin() + i+1,nums[i]+1);
            }
        }
        return ans;
    }
};