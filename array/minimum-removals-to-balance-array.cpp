// class Solution {
// public:
//     int minRemoval(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int ans = 0;

//         for(int i=0;i<nums.size();i++){
//             if(nums[i]*k < nums[nums.size()-1]) {
//                 ans++;
//                 nums.erase(nums.begin()+i);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            while ( (long long)nums[i] * k < (long long)nums[j]) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            // if((long long )nums[i]*k < (long long)nums[j]) {
            //     nums.erase(nums.begin()+i);
            //     j--;
            // }
        }
        
        return n - maxLen;
        // return n-nums.size();
    }
};