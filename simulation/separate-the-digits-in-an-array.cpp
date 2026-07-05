// class Solution {
// public:
//     vector<int> separateDigits(vector<int>& nums) {
//         vector<int> ans;
//         for(int i=0;i<nums.size();i++){
//             int e = nums[i];
//             vector<int> temp;
//             while(e){
//                 int dig = e%10;
//                 e/=10;
//                 temp.push_back(dig);
//             }
//             for(int j=temp.size()-1;j>=0;j--){
//                 ans.push_back(temp[j]);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto num:nums){
            string s = to_string(num);
            for(auto ch:s) ans.push_back(ch-'0');
        }
        return ans;
    }
};