class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int j=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            j++;
        }
        double maxsum=sum;
        for(int i=0;i<nums.size()-k;i++){
            sum=sum-nums[i];
            sum=sum+nums[j++];
            maxsum=max(sum,maxsum);
        }
        return maxsum/k;
    }
};