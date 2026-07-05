// class Solution {
// public:
//     double solve(double x, int n){
//         double i=n;
//         if(i<0) i = i*(-1);
//         double ans = 1.00000;
//         while(i>0){
//             ans=ans*x;
//             i--;
//         }
//         return ans;
//     }
    
//     double myPow(double x, int n) {
//         if(n==0) return 1.00000;
//         if(n==1) return x;
//         if(x==1) return 1.00000;
//         if(x==-1 && n%2==0) return 1;
//         if(x==-1 && n%2!=0) return -1;
//         if(n==-2147483648) return 0;

//         if(n<0){
//             // n = n*(-1);
//             return 1.00000/solve(x,n);
//         }
//         return solve(x,n);
//     }
// };


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;   // int ko long long me convert
        if(N < 0){
            x = 1 / x;
            N = -N;
        }

        double ans = 1.0;
        while(N > 0){
            if(N % 2 == 1)
                ans *= x;
            x *= x;
            N /= 2;
        }
        return ans;
    }
};
