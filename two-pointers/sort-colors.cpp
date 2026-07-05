class Solution {
public:
    int lowest (vector<int> nums,int l){
        int minn = l;
        for(int i=l+1;i<nums.size();i++){
            if(nums[minn]>nums[i]){
                minn=i;
            }
        }
        return minn;
    }

    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int minn = lowest(nums,i);
            swap(nums[minn],nums[i]);
        }
    }
};