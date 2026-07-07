class Solution {
public:
    int solve(int i,vector<int>& nums){
        if(i==nums.size()-1) return 1;
        if(i>=nums.size()) return INT_MAX-1;
        int ans = 0;
        int step = INT_MAX;
        for(int j=1;j<=nums.size();j++){
            ans = 1 + solve(i+j,nums);
            step = min(step,ans);
        }
        return step;
    }
    int jump(vector<int>& nums) {
        return solve(0,nums);
    }
};

