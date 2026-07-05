class Solution {
public:
    int getMin(vector<int> nums,int k,int minm){
        // if(nums.size()==1 && k==1) {
        //     return nums[0];
        // }
        // else if(nums.size()==2 && k==1){
        //     if(nums[0]>=nums[1]) return nums[0];
        //     return nums[1];
        // }
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        for(int i=n;i>n-k;i--){
            minm+=nums[i];
        }
        return minm; 
    }
    int getMax(vector<int> nums,int k,int maxm){
        // if(nums.size()==1 && k==1) {
        //     return nums[0];
        // }
        // else if(nums.size()==2 && k==1){
        //     if(nums[0]>=nums[1]) return nums[0];
        //     return nums[1];
        // }
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            maxm+=nums[i];
        }
        return maxm; 
    }
    int absDifference(vector<int>& nums, int k) {
        int a = getMax(nums,k,0);
        int b = getMin(nums,k,0);
        return abs(a-b);
    }
};