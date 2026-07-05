class Solution {
public:
    int getSum(int n){
        int s=0,d=0;
        while(n>0){
            int d = n%10;
            s += d*d;
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        while(n != 1 && n != 4){
            n = getSum(n);
        }
        return n == 1;
    }
};