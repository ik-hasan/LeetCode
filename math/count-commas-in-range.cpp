class Solution {
public:
    int countCommas(int n) {
        if(n<=999) return 0;
        int ans = 0;

        //1000 t0 9999
        if(n<=9999){
            for(int i=1000;i<=n;i++){
                ans+=1;
            }
        }
        else{
            //mtlb n > 9999
            for(int i=1000;i<=9999;i++){
                ans+=1;
            }
        }

        //10000 to 99999
        if(n<=99999){
            for(int i=10000;i<=n;i++){
                ans+=1;
            }
        }
        else{
            for(int i=10000;i<=99999;i++){
                ans+=1;
            }
        }

        if(n==100000) ans+=1;

        return ans;
    }
};







