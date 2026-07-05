class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> x;
        
        for (int i = 0; i < nums.size(); i++) {
            if (x.find(nums[i]) != x.end()) {
                // Duplicate found
                return true;
            }
            x[nums[i]] = true; 
        }
        return false; 
    }
};
