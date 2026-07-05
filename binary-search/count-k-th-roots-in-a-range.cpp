// class Solution {
// public:
//     int countKthRoots(int l, int r, int k) {

//         if(k==1) return r-l+1;

//         int ans = 0;
//         for(int i=1;i<=r;i++){
//             if(pow(i,k)<=r && pow(i,k)>=l) ans++;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int power(long long mid,int k,int r){
        long long res = 1;
        for(int i=1;i<=k;i++){
            if(res>(r/mid)) return r+1;
            res*=mid;
        }
        return res;
    }
    int countKthRoots(int l, int r, int k) {

        if(k==1) return r-l+1;
        long long low = 1, high = 1e9;

        int leftRoot=0,rightRoot=0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(power(mid,k,r)<=r){
                rightRoot = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        low = 1,high = 10e9;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(power(mid,k,r)>=l){
                leftRoot = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        int ans = rightRoot - leftRoot + 1;
        if(l==0)ans++;
        return ans;
    }
};