// class Solution {
// public:

//     void solve(vector<int> &nums,set<vector<int>> &ans,int index){
//         if(index >= nums.size()) {
//             ans.insert(nums);
//             return;
//         }

//         for(int i=index;i<nums.size();i++){
            
//             swap(nums[i],nums[index]);
//             solve(nums,ans,index+1);
//             swap(nums[i],nums[index]);
//         }
//         return;
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         set<vector<int>> st;
//         solve(nums,st,0);
//         vector<vector<int>> ans;
//         while(!st.empty()){
//             ans.push_back(*st.begin());
//             st.erase(st.begin());
//         }
//         return ans;
//     }
// };



class Solution {
public:

    void solve(vector<int> &nums,vector<vector<int>> &ans,int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;   
        for(int i=index;i<nums.size();i++){

            if(used.count(nums[i])) continue;   
            used.insert(nums[i]);              

            swap(nums[i],nums[index]);
            solve(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};