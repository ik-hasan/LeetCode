class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //direct use of Math STL
        // next_permutation(nums.begin(),nums.end());
        

        int edge = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                edge=i;
                break;
            }
        }
        if(edge==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>edge;i--){
            if(nums[i]>nums[edge]){
                swap(nums[i],nums[edge]);
                break;
            }
        }
        reverse(nums.begin()+edge+1,nums.end());
    }
};