class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int num = i;
            bool flag = true;
            bool changed = false;
            while(num!=0){
                int dig = num%10;
                if(dig==3 || dig ==4 || dig ==7 ){
                    flag = false;
                    break;
                }
                if(dig == 2 || dig == 5 || dig == 6 || dig == 9){
                    changed = true;
                }
                num = num/10;
            }
            if(flag && changed) ans++;
        }
        return ans;
    }
};