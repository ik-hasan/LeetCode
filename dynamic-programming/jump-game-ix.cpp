// class Solution {
// public:
//     vector<int> maxValue(vector<int>& nums) {
//         int high = INT_MIN;
//         vector<int> forward;
//         vector<int> backward(nums.size());

//         for(int i = 0;i<nums.size();i++){
//             high = max(high,nums[i]);
//             forward.push_back(high);
//         }

//         backward[nums.size()-1] = INT_MAX;
//         for(int i = nums.size()-2;i>=0;i--){
//             int elem = INT_MIN;
//             bool flag = true;
//             for(int j=i+1;j<nums.size();j++){
//                 if( nums[j] < nums[i] ){
//                     elem = max(elem,nums[j]);
//                     flag = false;
//                 }
//             }
//             if(flag) backward.push_back(nums[i]);
//             else backward.push_back(elem);
//         }

//         vector<int> ans;
//         for(int i=nums.size()-1; i>=0; i--){
//             if(forward[i] > nums[i]) {
//                 ans.push_back(forward[i]);
//             }
//             else ans.push_back(nums[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n), res(n);

        // prefix max
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        // suffix min
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        res[n - 1] = pre[n - 1];

        // build answer
        for (int i = n - 2; i >= 0; i--) {

            // merge segment
            if (pre[i] > suf[i + 1]) {
                res[i] = res[i + 1];
            }

            // new segment
            else {
                res[i] = pre[i];
            }
        }

        return res;
    }
};