// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> neg;
//         vector<int> pos;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]>0){
//                 pos.push_back(nums[i]);
//             }
//             else{
//                 neg.push_back(nums[i]);
//             }
//         }
//         vector<int> ans;
//         for(int i=0;i<n/2;i++){
//             ans.push_back(pos[i]);
//             ans.push_back(neg[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // final answer vector
        
        int posIndex = 0; // even index par positive jayega
        int negIndex = 1; // odd index par negative jayega
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};
