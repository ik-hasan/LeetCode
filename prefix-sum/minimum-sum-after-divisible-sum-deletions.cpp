// class Solution {
// public:
//     long long minArraySum(vector<int>& nums, int k) {
        
//         int n= nums.size();
//         //jo bhi k se devisible h unki val 0 set
//         for(auto &it:nums) if( it%k == 0 ) it=0;

//         vector<int> prefixSum(n);
//         prefixSum[0] = nums[0];
//         for(int i=1;i<n;i++){
//             prefixSum[i] += nums[i]+prefixSum[i-1];
//         }
//         if(prefixSum[n-1] % k==0) return 0;

//         for(int i=n-2;i>=0;i--){
//             if(prefixSum[i]%k==0) return prefixSum[i+1]-prefixSum[i];
//         }
//         return prefixSum[n-1];
//     }
// };


class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        unordered_map<long long,long long>mpp;
        mpp[0]=0;
        long long sum=0;// ye sum calc krta rhega throughout for rem calculation
        long long res=0;// jo hme calc krna h
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int r = sum % k;
            res += nums[i];
            // agr firse same rem milgya mtlb beech ka array remove krna h toh min store krlenge result m as we have to return min possible sum after deletion
            if(mpp.find(r)!=mpp.end()) res=min(res,mpp[r]);
            // agr nhi mila toh map m entry krdenge sum ki aur agr chota sum milgya h toh update krdenge map m
            else mpp[r]=res;
        }
        return res;
    }
};