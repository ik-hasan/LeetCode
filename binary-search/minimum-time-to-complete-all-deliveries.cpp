class Solution {
public:

    bool check(long long time, vector<int>& d, vector<int>& r){

        long long f1 = time - time/r[0];//drone 1 ka free time
        long long f2 = time - time/r[1];//drone 2 ka free time

        if(f1 < d[0] || f2 < d[1]) return false;

        long long bothBusy = time/(lcm(r[0],r[1]));//jb dono drone busy h
        long long remainingTime = time - bothBusy;
        return (d[0] + d[1] <= remainingTime);
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {

        long long low = 0;
        long long high = 1e18;
        long long ans = 1e18;

        while(low<=high){
            long long mid = low + (high - low)/2;
            if(check(mid,d,r)){
                // ans = min(ans,mid);
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};