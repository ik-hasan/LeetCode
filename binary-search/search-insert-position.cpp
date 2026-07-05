class Solution {
public:
    int search(vector<int> nums,int target,int s,int e){
        if(s>e) return s;
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return search(nums,target,s,mid-1);
        }
        else{
            return search(nums,target,mid+1,e);
        }
        // return mid;
    }
    int searchInsert(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int ans = search(nums,target,s,e);
        return ans;
    }
};