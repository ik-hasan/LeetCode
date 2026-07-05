class Solution {
public:

    // int summ(int end,int st,vector<int>& nums){
    //     int ans = 0;
    //     for(int i=st;i<=end;i++){
    //         ans+=nums[i];
    //     }
    //     return ans;
    // }
    
    // int pro(int st,int end,vector<int>& nums){
    //     int prod = 1;
    //     for(int i= st;i<=end;i++){
    //         prod*=nums[i];
    //     }
    //     return prod;
    // }
    
    // int smallestBalancedIndex(vector<int>& nums) {
    //     int ans = -1;

    //     for(int i=nums.size()-1;i>=0;i--){
    //         int currSum = summ(i-1,0,nums);
    //         int currProd = pro(i+1,nums.size()-1,nums);
    //         if(currSum == currProd) ans = i;
    //     }
    //     return ans;
    // }


    
    int smallestBalancedIndex(vector<int>& nums) {
        int ans = -1;

        vector<long long> prod(nums.size()+1,1);

        for(int i=nums.size()-1;i>=0;i--){
            if(prod[i+1] > 1e14/nums[i]) prod[i] = 1e14;
            else prod[i]=prod[i+1]*nums[i];
        }

        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum==prod[i+1]) return i;
            sum = sum + nums[i];
        }
        return -1;
    }
};