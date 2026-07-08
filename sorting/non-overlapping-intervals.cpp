// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intr) {
//         sort(intr.begin(),intr.end());

//         int checker = INT_MIN, ans= 0;
//         for(auto it:intr){
//             int st = it[0];
//             int end = it[1];
//             if(st>=checker){
//                 checker = end;
//             }
//             else ans++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intr) {

        sort(intr.begin(), intr.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int ans = 0, checker = INT_MIN;

        for(auto &it : intr){
            int st = it[0];
            int end = it[1];
            if(st >= checker) checker = end;
            else ans++;
        }
        return ans;
    }
};