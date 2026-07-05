class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int st = 0,end = nums.size()-1;

        while(st<=end){
            int mid = st+(end-st)/2;

            if(nums[mid]==target) return true;

            //for duplicates
            if(nums[st]==nums[mid] && nums[mid]==nums[end]){
                st++;
                end--;
            }

            //left half sorted
            else if(nums[st] <= nums[mid]){
                if(nums[st]<=target && nums[mid]>target){
                    end = mid-1;
                }
                else st = mid+1;
            }

            //right half sorted
            else if(nums[st] > nums[mid]){
                if(nums[mid] < target && target <=nums[end]){
                    st=mid+1;
                }
                else end = mid-1;
            }
        }
        return false;
    }
};