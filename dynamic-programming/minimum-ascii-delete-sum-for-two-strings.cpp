class Solution {
public:

    //PURE RECURSION
    // int solveRec(string& s1, string& s2, int i, int j){
    //     int cost = 0;
    //     if(i>=s1.length() || j>=s2.length()){
    //         for(int x=i;x<s1.length();x++) cost +=s1[x];
    //         for(int x=j;x<s2.length();x++) cost +=s2[x];
    //         return cost;
    //     }
    //     if( s1[i]==s2[j] ) return solve(s1,s2,i+1,j+1);
    //     else {
    //         int remF = s1[i] + solveRec(s1,s2,i+1,j);
    //         int remS = s2[j] + solveRec(s1,s2,i,j+1);
    //         cost = min(remF,remS);
    //     }
    //     return cost;
    // }
    // int minimumDeleteSum(string s1, string s2) {
    //     return solveRec(s1,s2,0,0);
    // }



    //MEMOIZATION
    int solveMem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        int cost = 0;
        if(i>=s1.length() || j>=s2.length()){
            for(int x=i;x<s1.length();x++) cost +=s1[x];
            for(int x=j;x<s2.length();x++) cost +=s2[x];
            return cost;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if( s1[i]==s2[j] ) return solveMem(s1,s2,i+1,j+1,dp);
        else {
            int remF = s1[i] + solveMem(s1,s2,i+1,j,dp);
            int remS = s2[j] + solveMem(s1,s2,i,j+1,dp);
            cost = min(remF,remS);
        }
        dp[i][j]=cost;
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solveMem(s1,s2,0,0,dp);
    }

};