class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        if(h==piles.size()) return high;
        int low = 1;
        int ans = 0;

        while(low<=high){
            int mid = low+(high-low)/2;
            int hr = h;
            for(int i=0;i<piles.size();i++){
                int x = (piles[i]+mid-1) / mid;//for ceiling val of temp/mid
                hr-=x;
            }
            if(hr>=0) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};