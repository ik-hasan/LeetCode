class Solution {
public:

    // int minValue(vector<int>&nums,int i){
    //     int minm = INT_MAX;
    //     for(int j=i+1;j<nums.size();j++){
    //         if(minm>nums[j]){
    //             minm = nums[j];
    //         }
    //     }
    //     return minm;
    // }
    // long long totalSum(vector<int>& nums,int i){
    //     long long sum = 0;
    //     for(int j = 0;j<=i;j++){
    //         sum += nums[j];
    //     }
    //     return sum;
    // }
    // long long solve(vector<int>& nums,int i,long long ans){
    //     if(i>=nums.size()-1) return ans;

    //     long long sum = totalSum(nums,i);
    //     long long minm = minValue(nums,i);
        
    //     ans = max(ans,sum-minm);

    //     return solve(nums,i+1,ans);
        
    // }
    // long long maximumScore(vector<int>& nums) {
    //     long long ans = LLONG_MIN;
    //     return solve(nums,0,ans);
    // }
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<int> rightMin(n);

        rightMin[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            rightMin[i] = min(rightMin[i+1],nums[i]);
        }

        long long prefixSum = 0;
        long long ans = LLONG_MIN;

        for(int i=0;i<n-1;i++){
            prefixSum += nums[i];
            ans = max(ans,prefixSum-rightMin[i+1]);
        }
        return ans;
    }
};