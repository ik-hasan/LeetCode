// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
        
//         int ans = INT_MIN;
//         int sum = 0;
//         vector<int> v=nums;
//         for(int i=0;i<nums.size();i++){
//             v.push_back(nums[i]);
//         }
//         int st =0;
//         int n = nums.size();
//         int j = 0;
//         for(int i=0;i<v.size();i++){
//             if(j!=0 && j%n==0 ){
//                 st++;
//                 ans = max(ans,sum);
//                 sum = 0;
//                 j=0;
//                 i=st;
//             }
//             sum += j*v[i];
//             j++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = 0;
        long long F = 0;
        
        // Step 1: sum and F(0)
        for(int i = 0; i < n; i++){
            sum += nums[i];
            F += i * nums[i];
        }
        
        long long ans = F;
        
        // Step 2: use formula
        for(int k = 1; k < n; k++){
            F = F + sum - n * nums[n - k];
            ans = max(ans, F);
        }
        
        return ans;
    }
};