class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1,-1};
        int st = 0, end = nums.size()-1;

        // FIRST OCCURRENCE
        while(st<=end){
            int mid = st + (end-st)/2;   
            if(nums[mid] < target) st = mid+1;
            else if(nums[mid] > target) end = mid-1;
            else{
                ans[0] = mid;           
                end = mid-1;//move left to find later index           
            }
        }
        st = 0;                         
        end = nums.size()-1;

        // LAST OCCURRENCE
        while(st<=end){
            int mid = st + (end-st)/2;   
            if(nums[mid] < target) st = mid+1;
            else if(nums[mid] > target) end = mid-1;
            else{
                ans[1] = mid;           
                st = mid+1;//move right to find later index
            }
        }
        return ans;                   
    }
};