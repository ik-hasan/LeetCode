class Solution {
public:
    int solve(int i,vector<int>& nums){
        if(i>=nums.size()-1) return 0;
        int ans = INT_MAX;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()) {
                int temp = solve(i+j,nums);
                if(temp!=INT_MAX) ans = min(ans,1 + temp);
            }
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        return solve(0,nums);
    }
};

