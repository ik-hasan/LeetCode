// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),inums.end());
//         do{
//             ans.push_back(nums);
//         }while(next_permutation(nums.begin(),nums.end()));
//         return ans;
//     }
// };



class Solution {
public:

    void solve(vector<int>& nums, int index,vector<vector<int>> &ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);  
            swap(nums[i],nums[index]);  
        }
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};