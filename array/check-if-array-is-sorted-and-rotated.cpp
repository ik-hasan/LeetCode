// class Solution {
// public:

//     int lowestElement(vector<int> nums){
//         int minIndex=0;
//         int i=1;
//         while(i<nums.size()){
//             if(nums[i]<nums[minIndex]){
//                 minIndex=i;
//             }
//             i++;
//         }
//         return minIndex;
//     }

//     bool checkSorted(vector<int> ans){
//         for(int i=1;i<ans.size();i++){ 
//             if(ans[i-1]>ans[i]){
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool check(vector<int>& nums) {
//         vector<int> ans;
//         int lowestIndex = lowestElement(nums);
//         if(lowestIndex==0){
//             if(checkSorted(nums)) return true;
//             else return false;
//             // return checkSorted(nums);
//         }
//         for(int i=lowestIndex;i<nums.size();i++){
//             ans.push_back(nums[i]);
//         }
//         for(int i=0;i<lowestIndex;i++){
//             ans.push_back(nums[i]);
//         }
//         if(checkSorted(ans)) return true;
//         else return false;
//         // return checkSorted(ans) && ans[0] >= ans.back();
//     }
// };

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Wrap around using modulo
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If more than 1 decrease found, not a rotated sorted array
            if (count > 1) return false;
        }

        return true;
    }
};
