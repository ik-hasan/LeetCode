class Solution {
public:
    int firstMin(vector<int>& nums){
        int x = INT_MAX;
        for(int i = 1; i < nums.size(); i++){  
            if(nums[i] < x) x = nums[i];
        }
        return x;                          
    }
    int secondMin(vector<int>& nums, int first){
        int y = INT_MAX;
        bool used = false;

        for(int i = 1; i < nums.size(); i++){  
            if(nums[i] == first && !used){
                used = true;               
                continue;
            }
            if(nums[i] < y) y = nums[i];
        }
        return y;
    }
    int minimumCost(vector<int>& nums) {
        int orgnlFirst = nums[0];
        int first = firstMin(nums);
        int second = secondMin(nums, first);

        return orgnlFirst + first + second;
    }
};



// class Solution {
// public:
//     int minimumCost(vector<int>& nums) {
//         int n = nums.size();
//         int first = nums[0];

//         int mn1 = INT_MAX, mn2 = INT_MAX;

//         for(int i = 1; i < n; i++){
//             if(nums[i] < mn1){
//                 mn2 = mn1;
//                 mn1 = nums[i];
//             } else if(nums[i] < mn2){
//                 mn2 = nums[i];
//             }
//         }

//         return first + mn1 + mn2;
//     }
// };
