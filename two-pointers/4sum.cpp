// class Solution {
// public:

//     void solve(vector<int>& nums, vector<int> temp,int target, vector<vector<int>> &ans, int i){
//         if( temp.size()==4 ) {
//             if(temp[0]+temp[1]+temp[2]+temp[3] == target) {
//                 ans.push_back(temp);
//             }
//             return;
//         }
//         if(i>=nums.size()) return;
//         temp.push_back(nums[i]);
//         solve(nums,temp,target,ans,i+1);
//         temp.pop_back();
//         solve(nums,temp,target,ans,i+1);
//         return;
//     }
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         vector<int> temp;
//         solve(nums,temp,target,ans,0);
//         for(auto &it:ans){
//             sort(it.begin(),it.end());
//         }
//         set<vector<int>> st;
//         for(auto it:ans){
//             st.insert(it);
//         }
//         vector<vector<int>> res;
//         while(!st.empty()){
//             res.push_back(*st.begin());
//             st.erase(*st.begin());
//         }
//         return res;
//     }

// };



class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans,
               int target,
               int idx,
               long long sum) {

        // base case
        if(temp.size() == 4) {

            if(sum == target)
                ans.push_back(temp);

            return;
        }

        for(int i = idx; i < nums.size(); i++) {

            // skip duplicates
            if(i > idx && nums[i] == nums[i-1])
                continue;

            temp.push_back(nums[i]);

            solve(nums,temp,ans,target,i + 1,sum + nums[i]);

            temp.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, temp, ans, target, 0, 0);

        return ans;
    }
};