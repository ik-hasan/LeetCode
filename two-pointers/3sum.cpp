class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element and use two pointers
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate fixed element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate 'left'
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicate 'right'
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++; // Increase sum
                }
                else {
                    right--; // Decrease sum
                }
            }
        }
        return ans;
    }
};
