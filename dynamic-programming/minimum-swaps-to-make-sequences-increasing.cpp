class Solution {
public:
    // int solve(vector<int>& nums1, vector<int>& nums2, int i, int p1,int p2){
    //     if(i>=nums1.size()) return 0;

    //     int inc=INT_MAX,exc=INT_MAX;

    //     if(p1<nums2[i] && p2<nums1[i]){
    //         inc = 1 + solve(nums1,nums2,i+1,nums2[i],nums1[i]);
    //     }
    //     if(p1<nums1[i] && p2<nums2[i]){
    //         exc = solve(nums1,nums2,i+1,nums1[i],nums2[i]);
    //     }
    //     return min(inc,exc);
    // }
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     int index = 0;
    //     return solve(nums1,nums2,index,-1,-1);
    // }
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int p1,int p2, vector<vector<int>> &dp, int isSwap){
        if(i>=nums1.size()) return 0;

        int inc=INT_MAX,exc=INT_MAX;

        if(dp[i][isSwap]!=-1) return dp[i][isSwap];

        if(p1<nums2[i] && p2<nums1[i]){
            inc = 1 + solve(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
        }
        if(p1<nums1[i] && p2<nums2[i]){
            exc = solve(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
        }
        dp[i][isSwap]=min(inc,exc);
        return dp[i][isSwap];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int index = 0;
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
        return solve(nums1,nums2,index,-1,-1,dp,0);
    }
};