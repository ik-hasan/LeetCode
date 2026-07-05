class Solution {
public:
    long long MOD = 1000000007;
    long long power(long long base,long long n){
        long long result = 1;
        while(n>0){
            if(n % 2 == 1) result = (result*base)%MOD;
            base = (base*base)%MOD;
            n=n/2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odds = n/2;
        long long evens = n-odds;

        long long ans1 = (power(5,evens))%MOD;
        long long ans2 = (power(4,odds))%MOD;

        return (ans1*ans2)%MOD;

    }
};