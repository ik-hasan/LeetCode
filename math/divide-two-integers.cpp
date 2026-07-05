class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        long long count = 0;
        long long  x = abs((long long)dividend);
        long long  y = abs((long long)divisor);

        int sign = 1;
        if( (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ) sign = -1;

        while(x >= y){
            x -= (long long)y;
            count++;
        }
        return (sign>0) ? count : -count;
    }
};

