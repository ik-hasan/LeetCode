class Solution {
public:

    void solve(vector<int> nums,int index,set<vector<int>> &st,vector<int> temp){
        if(index>=nums.size()){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            // temp.clear();
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,index+1,st,temp);
        temp.pop_back();
        solve(nums,index+1,st,temp);
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        solve(nums,0,st,temp);

        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(*st.begin());
            st.erase(*st.begin());
        }
        return ans;
    }
};