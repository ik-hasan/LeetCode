class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // if(m*k>n) return -1;
        int ans=-1;
        int low =1,high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = 0;
            int iter = 0;
            for(auto it:bloomDay){
                if(mid>=it) {
                    iter++;
                    if(iter==k){
                        cnt = cnt+iter;
                        iter=0;
                    }
                }
                else iter = 0;
            }
            long long temp = (long long)m*(long long)k;
            if(temp <= cnt) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};