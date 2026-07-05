class Solution {
public:
    const long long MOD = 1e9+7;

    long long modpow(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1) res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return res;
    }

    long long nCr(int n,int r){
        if(r<0 || r>n) return 0;
        long long num=1,den=1;
        for(int i=0;i<r;i++){
            num=num*(n-i)%MOD;
            den=den*(i+1)%MOD;
        }
        return num*modpow(den,MOD-2)%MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        return (2 * nCr(n-1,k)) % MOD;
    }
};