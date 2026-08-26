class Solution {
public:

    int solve(int st, int end, string & s){
        if(st>=end) return 0;
        if(s[st]==s[end]) return solve(st+1,end-1,s);
        return 1 + min(solve(st+1,end,s), solve(st,end-1,s));
    }
    int minInsertions(string s) {
        int n = s.length();
        return solve(0,n-1,s);
    }
};