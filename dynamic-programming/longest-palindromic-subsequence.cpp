class Solution {
public:
    int solve(int start, int end, string &s) {
        if(start > end)
            return 0;

        if(start == end)
            return 1;

        if(s[start] == s[end])
            return 2 + solve(start+1, end-1, s);

        return max(
            solve(start+1, end, s),
            solve(start, end-1, s)
        );
    }
    int longestPalindromeSubseq(string s) {
        return solve(0, s.length()-1, s);
    }
};