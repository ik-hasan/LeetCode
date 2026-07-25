class Solution {
public:

    int solve(int i,vector<int> &nums, vector<int> &temp, int totalSum){
        if(temp.size()==nums.size()/2) {
            int sum1 = accumulate(temp.begin(),temp.end(),0);
            int sum2 = totalSum-sum1;
            return abs(sum1-sum2);
        } 
        if(i>=nums.size()) return INT_MAX;

        temp.push_back(nums[i]);
        int take = solve(i+1,nums,temp,totalSum);
        temp.pop_back();
        int notTake = solve(i+1,nums,temp,totalSum);
        return min(take,notTake);
        
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        // int cnt 
        vector<int> temp;
        return solve(0,nums,temp,totalSum);
    }
};