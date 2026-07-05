class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> counts; 
        // int n = nums.size();

        // for (int num : nums) {
        //     counts[num]++;  
        //     if (counts[num] > n / 2) {  
        //         return num;
        //     }
        // }
        // return -1;

        int focusElement = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == focusElement) {
                count++;
            } 
            else {
                count--;
                if (count == 0) {
                    focusElement = nums[i];
                    count = 1;
                }
            }
        }

        return focusElement;
    }
};