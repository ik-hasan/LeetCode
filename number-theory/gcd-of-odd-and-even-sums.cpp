class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a=0,b=0;
        for(int i=0;i<=2*n;i++){
            if(i%2==0) a += i;
            else b += i;
        }
        //a aur b tayyar for gcd
        // int x = max(a,b);
        // for(int i=x;i>=0;i--){
        //     if(a%i==0 && b%i==0){
        //         return i;
        //     }
        // }
        return __gcd(a,b);
    }
};