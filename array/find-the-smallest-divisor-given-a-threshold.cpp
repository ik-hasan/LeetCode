class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int low = 1,high = *max_element(nums.begin(),nums.end());
        if(t==n) return high;
        int ans = 0;

        while(low<=high){
            int mid = low+(high-low)/2;
            int res = 0;
            for(auto it:nums){
                res += (it+mid-1)/mid;
            }
            if(res <= t) {
                high = mid-1;
                ans = mid;
            } 
            else low = mid+1;
        }
        return ans;
    }   
};