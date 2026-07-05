class Solution {
public:

    //hmara logic shi h bs DP lga kr Optimize krna h fir TLE nhi marega
    // bool solve(vector<int> nums,int index){
    //     if(index >= nums.size()) return false;
    //     if(index == nums.size()-1) return true;

    //     bool ans =false;
    //     for(int i=1;i<=nums[index];i++){
    //         ans = ans || solve(nums,index+i);
    //     }
    //     return ans;
    // }
    // bool canJump(vector<int>& nums) {
    //     int index = 0;
    //     return solve(nums,index);
    // }

    //DP SOLN OF ABOVE CODE
    // bool solveDP(vector<int> &nums,int index,vector<int>& dp_arr){
    //     if(index >= nums.size()) return false;
    //     if(index == nums.size()-1) return true;

    //     // step-3 check if ans already exist in dp_arr
    //     if(dp_arr[index] != -1){
    //         return dp_arr[index];
    //     }

    //     bool ans =false;
    //     for(int i=1;i<=nums[index];i++){
    //         ans = ans || solveDP(nums,index+i,dp_arr);
    //         if(ans) return true;//agr ek bhi bar true ho gya to fir aage check krne ki need nhi h sidha true return krdo.
    //     }

    //     //step-2 store rec ans in dp_arr and return
    //     dp_arr[index] = ans;
    //     return dp_arr[index];
    // }
    // bool canJump(vector<int>& nums) {
    //     int index = 0;
    //     int n = nums.size();

    //     //step-1 create a dp_arr and pass
    //     vector<int> dp_arr(n,-1);
    //     return solveDP(nums,index,dp_arr);
    // }



    bool solve(vector<int>& nums,int index,vector<int> &dp){
        if(index == nums.size() ) return false;
        if(index == nums.size()-1 ) return true;
        if(dp[index]!=-1) return dp[index];
        bool ans = false;
        for(int i = 1; i<=nums[index]; i++){
            ans = ans || solve(nums,index+i,dp);
            if(ans) return true;
        }
        dp[index]=ans;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }









};
















