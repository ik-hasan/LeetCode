class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int n = weights.size();
        int ans = 0; 

        while(low<=high){
            int mid = low+(high-low)/2;
            int temp = mid;
            int day = 1;
            for(int  i=0;i<n;i++){
                temp -= weights[i];
                if(temp<0){
                    day++;
                    temp = mid-weights[i];
                }
            }
            if(day<=days) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};