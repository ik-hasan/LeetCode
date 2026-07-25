class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        
        int n= nums.size();
        //jo bhi k se devisible h unki val 0 set
        for(auto &it:nums) if( it%k == 0 ) it=0;

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] += nums[i]+prefixSum[i-1];
        }
        if(prefixSum[n-1] % k==0) return 0;

        for(int i=n-2;i>=0;i--){
            if(prefixSum[i]%k==0) return prefixSum[i+1]-prefixSum[i];
        }
        return 0;
    }
};