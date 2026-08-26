class Solution {
public:

    string solve(int i, int j, string &s1, string &s2, vector<vector<string>> &dp){
        if(i<=s1.length()-1 && j>s2.length()-1) return s1.substr(i,s1.length()-i);
        if(j<=s2.length()-1 && i>s1.length()-1) return s2.substr(j,s2.length()-j);
        if(i>=s1.length() || j>=s2.length()) return "";

        if(dp[i][j]!= "$") return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = s1[i] + solve(i+1,j+1,s1,s2,dp);

        string a = s1[i] + solve(i+1,j,s1,s2,dp);
        string b = s2[j] + solve(i,j+1,s1,s2,dp);

        return dp[i][j] = (a.length()>b.length()) ? b : a;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<string>> dp(str1.length(),vector<string>(str2.length(),"$"));
        return solve(0,0,str1,str2,dp);
    }
};