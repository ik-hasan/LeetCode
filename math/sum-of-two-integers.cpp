class Solution {
public:
    int getSum(int a, int b) {
        int xxor = a^b;
        int carry = (a & b)<<1;
        return xxor+carry;
    }
};