class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int ans = INT_MIN,l=0,r=0;
        unordered_map<int,int> freq;
        while(r<nums.size()){
            freq[nums[r]]++;
            while(freq[nums[r]]>k && l<nums.size()){
                freq[nums[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};