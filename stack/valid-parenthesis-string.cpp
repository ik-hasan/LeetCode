class Solution {
public:
    bool solve(int open, int i, string &s, vector<vector<int>> &dp){
        if(open < 0) return false;
        if(i == s.size()) return open == 0;
        if(dp[i][open]!=-1) return dp[i][open];

        bool a=false,b=false,c=false;
        if(s[i]=='(') a = solve(open+1,i+1,s,dp);
        else if(s[i]==')') b = solve(open-1, i+1,s,dp);
        else{
            c = solve(open+1,i+1,s,dp) || //'('
            solve(open-1,i+1,s,dp) || //')'
            solve(open,i+1,s,dp); //empty string
        }
        dp[i][open] = a || b || c;
        return dp[i][open];
    }
    bool checkValidString(string s) {
        int open = 0;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(open,0,s,dp);
    }
};
