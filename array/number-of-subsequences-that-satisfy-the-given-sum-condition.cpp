// class Solution {
// public:
//     long long maxx(vector<long long>& temp){
//         long long ans = INT_MIN;
//         for(auto it:temp){
//             ans = max(ans,it);
//         }
//         return ans;
//     }
//     long long minn(vector<long long>& temp){
//         long long ans = INT_MAX;
//         for(auto it:temp){
//             ans = min(ans,it);
//         }
//         return ans;
//     }

//     long long ans = -1;
//     void solve(vector<int>& nums,int index,int &target,vector<long long> temp){
//         if(index>=nums.size()){
//             long long minm = minn(temp);
//             long long maxm = maxx(temp);
//             if(minm+maxm <= target) ans++;
//             return;
//         }

//         temp.push_back(nums[index]);
//         solve(nums,index+1,target,temp);
//         temp.pop_back();
//         solve(nums,index+1,target,temp);
//         return;
//     }

//     long long MOD = 1000000007;
//     int numSubseq(vector<int>& nums, int target) {
//         vector<long long> temp;
//         solve(nums,0,target,temp);

//         return ans%MOD;
//     }
// };



// class Solution {
// public:

//     long long ans = 0;
//     long long MOD = 1000000007;

//     void solve(vector<int>& nums, int index, int target, vector<int>& temp, long long currMin, long long currMax){

//         if(index >= nums.size()){
//             if(temp.size() > 0 && currMin + currMax <= target) ans++;
//             return;
//         }
//         // include
//         temp.push_back(nums[index]);

//         long long newMin = min(currMin,(long long)nums[index]); 
//         long long newMax = max(currMax,(long long)nums[index]); 

//         solve(nums,index+1,target,temp,newMin,newMax);

//         temp.pop_back();

//         // exclude
//         solve(nums,index+1,target,temp,currMin,currMax);
//     }

//     int numSubseq(vector<int>& nums, int target) {

//         vector<int> temp;
//         solve(nums,0,target,temp,LLONG_MAX,LLONG_MIN);
//         return ans % MOD;
//     }
// };



class Solution {
public:

    long long ans = 0;
    long long MOD = 1000000007;

    long long power(long long base, long long n){
        long long res = 1;
        while(n>0){
            if(n%2==1) res = (res*base)%MOD;
            base = (base*base)%MOD;
            n=n/2;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0,right = n-1;

        while(left<=right){
            if(nums[left]+nums[right] <= target){
                ans = (ans + power(2,right-left))%MOD;
                ans = ans % MOD;
                left++;
            }
            else right--;
        }
        return ans;
    }
};








