class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxx = INT_MIN;
        long long minn = INT_MAX;

        for(long long  it:nums){
            maxx = max(maxx,it);
            minn = min(minn,it);
        }

        return (maxx-minn)*k;
    }
};