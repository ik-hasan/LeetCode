class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> check;
        for(int i=0;i<nums.size();i++){
            if(check.find(nums[i]) != check.end() ){
                return nums[i];
            }
            check[nums[i]]=true;
        }
        return -1;
    }
};