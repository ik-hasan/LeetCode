class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            long long dom = nums[i];
            long long sum = 0;
            long long count = 0;
            for(int j=i+1;j<nums.size();j++){
                sum += nums[j];
                count++;
            }
            if(dom*count  > sum) ans++;
        }
        return ans;
    }
};