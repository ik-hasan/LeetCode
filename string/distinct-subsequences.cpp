class Solution {
public:

    int solve(int i, string &s, string &t, string temp){
        if(temp==t) return 1;
        if(i>=s.length()) return 0;
        int take = solve(i+1,s,t,temp+s[i]);
        int notTake = solve(i+1,s,t,temp);
        return take+notTake;
    }
    int numDistinct(string s, string t) {
        if(s.length() < t.length()) return 0;
        string temp = "";
        return solve(0,s,t,temp);
    }
};