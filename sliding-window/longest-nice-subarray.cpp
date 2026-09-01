class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int l=0;
        int ans = 0;
        int mask = 0;
        for(int r=0;r<nums.size();r++){
            while(mask & nums[r]){
                mask ^= nums[l];
                l++;
            }
            mask |= nums[r];
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};