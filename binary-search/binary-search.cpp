class Solution {
public:

    int bs(vector<int>& nums,int st,int end, int &target){
        // if(st>end) return -1;
        while(st<=end){
            int mid = (st+end)/2;
            if(target==nums[mid]) return mid;
            else if(target > nums[mid]) return bs(nums,mid+1,end,target);
            else return bs(nums,st,mid-1,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int st = 0,end = nums.size()-1;
        return bs(nums,st,end,target);
    }
};