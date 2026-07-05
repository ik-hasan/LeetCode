class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st = 0;
        int end = nums.size()-1;
        int ans = 0;

        for(int i=0;i<nums.size()/2;i++){
            int sum = nums[st]+nums[end];
            ans = max(ans,sum);
            st++;
            end--;
        }
        return ans;
    }
};