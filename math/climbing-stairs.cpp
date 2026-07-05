// class Solution {
// public:
//     int solve(int n,int end,vector<int> arr){
//         if(end==n) return 1;
//         if(end>n) return 0;
//         if(arr[end]!=-1){
//             return arr[end];
//         }
//         int inc1 = solve(n,end+1,arr);
//         int inc2 = solve(n,end+2,arr);
//         arr[end] = inc1+inc2;
//         return arr[end];
//     }
//     int climbStairs(int n) {
//         vector<int> arr(n+1,-1);
//         return solve(n,0,arr);
//     }
// };
class Solution {
public:
    int solve(int n, int end, vector<int>& arr) {
        if (end == n) return 1;
        if (end > n) return 0;

        if (arr[end] != -1) {
            return arr[end];
        }

        int inc1 = solve(n, end + 1, arr);
        int inc2 = solve(n, end + 2, arr);

        arr[end] = inc1 + inc2;
        return arr[end];
    }

    int climbStairs(int n) {
        vector<int> arr(n + 1, -1);
        return solve(n, 0, arr);
    }
};
