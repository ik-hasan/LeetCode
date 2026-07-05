//PURE REC WITH TLE
// class Solution {
// public:
//     int solveUsingRec(vector<int>& arr, int curr, int prev) {
//         if (curr >= arr.size()) return 0;

//         int inc = 0;
//         if (prev == -1 || arr[curr] > arr[prev]) {
//             inc = 1 + solveUsingRec(arr, curr + 1, curr);
//         }

//         int exc = solveUsingRec(arr, curr + 1, prev);

//         return max(inc, exc);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         return solveUsingRec(nums, 0, -1);
//     }
// };



//MEMOISATION
// class Solution {
// public:
//     int solveUsingMem(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp) {
//         if (curr >= arr.size()) return 0;

//         if (dp[curr][prev + 1] != -1)
//             return dp[curr][prev + 1];

//         int inc = 0;
//         if (prev == -1 || arr[curr] > arr[prev]) {
//             inc = 1 + solveUsingMem(arr, curr + 1, curr, dp);
//         }

//         int exc = solveUsingMem(arr, curr + 1, prev, dp);

//         dp[curr][prev + 1] = max(inc, exc);
//         return dp[curr][prev + 1] ;
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));
//         return solveUsingMem(nums, 0, -1, dp);
//     }
// };


//TABULATION
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //step-1 create dp array, curr->row, prev->col
        vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));

        //step-2 analyze base case & update dp array
        for(int prev = 0; prev <= n; prev++){
            dp[n][prev] = 0;
        }


        //step-3
        for(int curr =n-1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int inc = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    inc = 1 + dp[curr + 1][curr+1];
                }

                int exc = dp[curr + 1][prev+1];//when curr =0, then prev will be -1 which is invalid, so we prev+1
                dp[curr][prev + 1] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
};



//TC-O(log n) ye smjh nhi aaya utna 
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {

//         vector<int> ans;
//         ans.push_back(nums[0]);

//         for(int i=1;i<nums.size();i++){
//             if(nums[i] > ans.back()){
//                 ans.push_back(nums[i]);
//             }
//             else{
//                 auto x = lower_bound(ans.begin(),ans.end(),nums[i]);
//                 int index = x - ans.begin();
//                 ans[index]=nums[i];
//             }
//         }
//         return ans.size();
//     }
// };