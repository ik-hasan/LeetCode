// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
        
//         vector<int> ans;
//         int n=nums.size();
//         k = k % n;//if k > n hua uske liye 
//         for(int i=n-k;i<n;i++){
//             ans.push_back(nums[i]);
//         }
//         for(int i=0;i<n-k;i++){
//             ans.push_back(nums[i]);
//         }
//         for(int i=0;i<nums.size();i++){
//             nums[i]=ans[i];
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) { 
        int n=nums.size();
        k = k % n;//if k > n hua uske liye 
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};