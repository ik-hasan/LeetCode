//standard soln
class Solution {
public:
    int oddsLessThanK(vector<int>& nums, int k){
        int l=0,r=0,ans=0,odds=0;
        while(r<nums.size()){
            odds += nums[r]%2;//count odds
            while(odds>k){
                if(nums[l]%2) odds--;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return oddsLessThanK(nums,k) - oddsLessThanK(nums,k-1);
    }
};

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         for(auto &it:nums){
//             if(it%2==0) it = 0;
//             else it = 1;
//         }

//         int n = nums.size();
//         int ans = 0;
//         unordered_map<int,int> prefixSum;
//         prefixSum[0] = 1;
//         int currSum = 0;
//         for(int i=0;i<n;i++){
//             currSum += nums[i];

//             if(prefixSum.find(currSum-k) != prefixSum.end()) {
//                 ans += prefixSum[currSum-k];
//             }
//             prefixSum[currSum]++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int l=0,ans=0,odds=0,prefix=0;

//         for(int r=0;r<nums.size();r++){
//             if(nums[r]%2){
//                 odds++;
//                 prefix=0;
//             }
//             while(odds==k){
//                 prefix++;
//                 if(nums[l]%2) odds--;
//                 l++;
//             }
//             ans += prefix;
//         } 
//         return ans;  
//     }
// };
// prefix = Current window me first odd ke pehle kitne even pade hain & fir current window ke last odd ke bad jitne bhi even pde h, sbke liye ans+=prefix hoga
// Aur jab naya odd aata hai: prefix = 0, kyunki ab puri kahani badal gayi, ab current window ke new starting odd aur ending odd mil gye.