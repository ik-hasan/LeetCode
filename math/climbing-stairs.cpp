class Solution {
public:
    int solve(int i, int n){
        if(i==n) return 1;
        if(i>n) return 0;

        int a = solve(i+1,n);
        int b = solve(i+2,n);
        return a+b;
    }
    int climbStairs(int n) {
        return solve(0,n);
    }
};