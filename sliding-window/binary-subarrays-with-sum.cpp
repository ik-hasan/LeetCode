// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int l = 0, sum = 0, ans = 0;
//         int prefixZeros = 0;
//         for(int r = 0; r < nums.size(); r++) {
//             sum += nums[r];
//             while(l < r && (sum > goal || nums[l] == 0)) {
//                 if(nums[l] == 0) prefixZeros++;
//                 else prefixZeros = 0;
//                 sum -= nums[l];
//                 l++;
//             }
//             if(sum == goal) ans += 1 + prefixZeros;
//         }
//         return ans;
//     }
// };




class Solution {
public:
    int sumLessThanGoal(vector<int>& nums, int goal){
        int l=0,r=0,ans=0,sum=0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            if(sum<=goal) ans += r-l+1;//goal se <= wale sbhi consider
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumLessThanGoal(nums,goal) - sumLessThanGoal(nums,goal-1);
    }
};