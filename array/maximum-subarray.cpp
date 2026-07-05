class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int high = INT_MIN;
        for(auto it:nums) high=max(high,it);
        int ans = high;
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>=0){
                sum=sum+nums[i];
                ans = max(ans,sum);
            }
            else{
                sum = 0;
            }
        }
        return ans;
    }
};