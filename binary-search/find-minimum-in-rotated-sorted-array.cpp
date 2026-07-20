class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1, ans = INT_MAX;

        while(s<=e){
            int mid = s+(e-s)/2;
            ans = min(ans,nums[mid]);

            if(nums[s]<=nums[mid] && nums[mid]<=nums[e]){
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};