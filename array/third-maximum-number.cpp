// class Solution {
// public:
//     int thirdMax(vector<int>& nums) { 
//         int max1 = INT_MIN;
//         int max2 = INT_MIN;
//         int max3 = INT_MIN;
//         for(auto x:nums){
//             if(max1 == x || max2 == x || max3 == x) continue;//skip duplicate
//             if(max1 < x){
//                 max3 = max2;
//                 max2 = max1;
//                 max1 = x;
//             }
//             else if(max2 < x){
//                 max3 = max2;
//                 max2 = x;
//             }
//             else if(max3 < x){
//                 max3 = x;
//             }
//         }
//         if(max3 == INT_MIN) return max1;
//         return max3;
//     }
// };

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        for(long long x : nums){
            if(x == a || x == b || x == c) continue;
            if(x > a){
                c = b;
                b = a;
                a = x;
            }
            else if(x > b){
                c = b;
                b = x;
            }
            else if(x > c){
                c = x;
            }
        }
        return (c == LLONG_MIN ? a : c);
    }
};
