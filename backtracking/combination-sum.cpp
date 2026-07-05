class Solution {
public:

    void solve(vector<int> temp, set<vector<int>> &ans, vector<int> &v,int &target,int index,int sum){
        if(sum==target){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(sum > target) return;

        for(int i=0;i<v.size();i++){
            sum+=v[i];
            temp.push_back(v[i]);
            solve(temp,ans,v,target,index+1,sum);
            sum-=v[i];
            temp.pop_back();
        }
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        set<vector<int>> st;
        solve(temp,st,candidates,target,0,0);
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(*st.begin());
            st.erase(*st.begin());
        }
        return ans;
    }
};


// SOLN-1
// class Solution {
// public:
//     void solve(vector<int>& candidates, int target, vector<int>& temp,vector<vector<int>>&ans, int index,int sum){

//         if(sum==target){
//             ans.push_back(temp);
//             return;
//         }
//         if(sum>target || index>=candidates.size()){
//             return;
//         }
//         for(int j=index;j<candidates.size();j++){
//             sum+=candidates[j];
//             temp.push_back(candidates[j]);
//             solve(candidates,target,temp,ans,j,sum);
//             sum-=candidates[j];
//             temp.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> temp;
//         vector<vector<int>> ans;
//         solve(candidates,target,temp,ans,0,0);
//         return ans;
//     }
// };


//SOLN-2
// class Solution {
// public:
//     void solve(vector<int>& candidates, int target, vector<int>& temp,vector<vector<int>>&ans, int index){

//         if(target == 0) {
//             ans.push_back(temp);
//             return;
//         }
//         if( target < 0 ) return;

//         for(int i=index;i<candidates.size();i++){

//             target -= candidates[i];
//             temp.push_back(candidates[i]);
//             solve(candidates,target,temp,ans,i);
//             target += candidates[i];
//             temp.pop_back();

//         }
//         return;
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> temp;
//         vector<vector<int>> ans;
//         solve(candidates,target,temp,ans,0);
//         return ans;
//     }
// };