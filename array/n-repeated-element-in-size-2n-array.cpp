class Solution {
public:

    //soln-1 brute force
    // int repeatedNTimes(vector<int>& nums) {
    //     int length = nums.size();
    //     int n = length/2;
    //     unordered_map<int,int> mp;
    //     for(auto &e:nums){
    //         mp[e]++;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(mp[nums[i]]==n) return nums[i];
    //     }
    //     return 0;
    // }


    //soln-2 optimized
    int repeatedNTimes(vector<int>& nums) {
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return nums[i];
            if( i+2 < nums.size() && nums[i]==nums[i+2]) return nums[i];
            if( i+3 < nums.size() && nums[i]==nums[i+3]) return nums[i];
        }
        return -1;
    }
};