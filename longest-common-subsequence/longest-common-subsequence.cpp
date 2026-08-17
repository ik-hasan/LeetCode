class Solution {
public:

    int solve(int i, int j, string &text1, string &text2){
        if(i>=text1.size() || j>=text2.size()) return 0;
        if(text1[i]==text2[j]) return 1+solve(i+1,j+1,text1,text2);

        return max(solve(i+1,j,text1,text2), solve(i,j+1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(0,0,text1,text2);
    }
};