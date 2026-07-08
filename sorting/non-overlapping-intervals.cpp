class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(),intr.end());

        int checker = INT_MIN, ans= 0;
        for(auto it:intr){
            int st = it[0];
            int end = it[1];
            if(st>=checker){
                checker = end;
            }
            else ans++;
        }
        return ans;
    }
};