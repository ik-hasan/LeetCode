// class Solution {
// public:
//     bool isPrime(int n){
//         if(n<2) return false;
//         for(int i=2;i*i<=n;i++){
//             if(n%i==0) return false;
//         }
//         return true;
//     }
    
//     int nextPrime(int n){
//         while(!isPrime(n)) n++;
//         return n;
//     }
    
//     int minOperations(vector<int>& nums) {
//         int ans = 0;
//         for(int i=0;i<nums.size();i++){
//             if(i%2){
//                 //odd index -> non prime
//                 int x = nums[i];
//                 while(isPrime(x)) x++;
//                 ans += x-nums[i];
//             }
//             else{
//                 //even index -> prime
//                 if(!isPrime(nums[i])){
//                     int p = nextPrime(nums[i]);
//                     ans += p-nums[i];
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int maxx = 200000;
        vector<bool> prime(maxx+1,true);
        prime[0]=false;
        prime[1]=false;

        //creating prime array 
        for(int i=2;i*i<=maxx;i++){
            if(prime[i]){
                for(int j=i*i;j<=maxx;j+=i){
                    prime[j]=false;
                }
            }
        }

        //creating next prime array 
        vector<int> nextPrime(maxx+2);
        int lastPrime = -1;
        for(int i=maxx;i>=0;i--){
            if(prime[i]) lastPrime = i;
            nextPrime[i]=lastPrime;
        }

        for(int i=0;i<nums.size();i++){
            if(i%2){
                //odd index -> non prime
                if(prime[nums[i]]) {
                    int x = nums[i];
                    while(prime[x]) x++;
                    ans += x-nums[i];
                }
            }
            else{
                //even index -> prime
                if(!prime[nums[i]]){
                    ans += nextPrime[nums[i]] - nums[i];
                }
            }
        }
        return ans;
    }
};