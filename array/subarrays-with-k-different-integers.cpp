class Solution {
public:
    int lessThanKDiffElements(vector<int>& nums, int k){
        int l=0,r=0,ans=0;
        unordered_map<int,int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                //more than k diff elements are there in subarray
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessThanKDiffElements(nums,k) - lessThanKDiffElements(nums,k-1);
    }
};