class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxx(n);
        maxx[0]=nums[0];
        vector<int> minn(n);
        minn[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            maxx[i] = max(maxx[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            minn[i] = min(minn[i+1],nums[i]);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int x = maxx[i]-minn[i];
            if(x<=k) return i;
        }
        return -1;
    }
};