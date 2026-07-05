class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int st = 0;
        int end = nums.size()-1;

        int ans = INT_MAX;

        while(st<=end){
            int mid = st+(end-st)/2;

            //left half sorted
            if(nums[st]<=nums[mid]){
                ans = min(ans,nums[st]);
                st = mid+1;
            }
            //right half sorted
            else if(nums[st]>nums[mid]){
                ans = min(ans,nums[mid]);
                end = mid-1;
            }
        }
        return ans;
    }
};