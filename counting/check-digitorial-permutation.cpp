class Solution {
public:

    int fact(int n){
        int res = 1;
        for(int i=1;i<=n;i++){
            res *= i;
        }
        return res;
    }
    bool isDigitorialPermutation(int n) {
        int factSum = 0;
        int check = n;
        
        while(check>0){
            int digit = check%10;
            int x = fact(digit);
            check=check/10;
            factSum+=x;
        }
        
        int a[10]={0};
        int b[10]={0};
        while(factSum > 0){
            int digit = factSum % 10;
            factSum= factSum/10;
            a[digit]++;
        }
        while(n > 0){
            int digit = n % 10;
            n= n/10;
            b[digit]++;
        }
        for(int i=0;i<10;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};