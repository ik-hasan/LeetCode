//TLE
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int ans = INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             int sum = 0;
//             for(int j=i;j<nums.size();j++){
//                 sum += nums[j];
//                 if(sum >= target){
//                     ans = min(ans,j-i+1);
//                     break;
//                 }
//             }
//         }
//         return (ans==INT_MAX) ? 0 : ans;
//     }
// };




//sliding window expand & shrink
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int st = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum<target) continue;
            else {
                ans = min(ans,i-st+1);
                while(sum>=target){
                    sum -= nums[st];
                    st++;
                    if(sum>=target){
                        ans = min(ans,i-st+1);
                    }
                }
            } 
        }
        return (ans==INT_MAX) ? 0 : ans;
    }
};






