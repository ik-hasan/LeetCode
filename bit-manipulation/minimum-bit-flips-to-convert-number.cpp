class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int ans = 0;
        while(cnt < 32){
            int checkGoalBit = goal & (1<<cnt);
            int checkStartBit = start & (1<<cnt);
            if( checkGoalBit == checkStartBit){
                cnt++;
                continue;
            }
            else{
                ans++;
            }
            cnt++;
        }
        return ans;
    }
};