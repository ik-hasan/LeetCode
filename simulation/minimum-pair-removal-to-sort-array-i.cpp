class Solution {
public:
    int minPos(vector<int> nums){
        int min = INT_MAX;
        int pos = -1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] < min){
                min = nums[i]+nums[i+1];
                pos = i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &nums,int pos){
        nums[pos] = nums[pos]+nums[pos+1];
        nums.erase(nums.begin()+pos+1);
    }


    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(!is_sorted(nums.begin(),nums.end() )){
            ans++;
            mergePair(nums,minPos(nums));
        }
        return ans;
    }
};