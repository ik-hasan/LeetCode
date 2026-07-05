class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int leftSum=0,rightSum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                leftSum+=nums[j];
            }
            for(int k=i+1;k<nums.size();k++){
                rightSum+=nums[k];
            }
            if(leftSum==rightSum){
                return i;
            }
            else{
                leftSum=0;
                rightSum=0;
            }
        }
        return -1;
    }
};