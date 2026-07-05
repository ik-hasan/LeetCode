// class Solution {
// public:
//     int xorOperation(int n, int start) {
//         vector<int> nums(n);
//         for(int i=0;i<n;i++){
//             nums[i]=  start + 2 * i;
//         }
//         int ans = 0;
//         for(int i=0;i<nums.size();i++){
//             ans = ans ^ nums[i];
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans ^ start + 2 * i;
        }
        return ans;
    }
};