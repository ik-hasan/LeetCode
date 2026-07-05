class Solution {
public:
    bool compare(string s, vector<string> wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s==wordDict[i]) return true;
        }
        return false;
    }



    //REC WITH TLE
    // bool solveRec(string s, vector<string>& wordDict,int i, int j){
    //     if(j>=s.size() && i>=s.size()) return true;
    //     if(j==s.size() && i<s.size()) return false;
    //     if( compare(s.substr(i,j-i+1), wordDict) ){
    //         if(solveRec(s,wordDict,j+1,j+1)) return true;
    //     }
    //     return solveRec(s,wordDict,i,j+1);
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     return solveRec(s,wordDict,0,0);
    // }



    //MEM
    bool solveMem(string s, vector<string>& wordDict,int i, int j,vector<vector<int>> &dp){
        if(j>=s.size() && i>=s.size()) return true;
        if(j==s.size() && i<s.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];
        if( compare(s.substr(i,j-i+1), wordDict) ){
            if(solveMem(s,wordDict,j+1,j+1,dp)) return true;
        }
        dp[i][j] = solveMem(s,wordDict,i,j+1,dp);
        return dp[i][j];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(s,wordDict,0,0,dp);
    }



    //TABULATION YE PTA NHI KYU NHI CHAL RHA
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     int n = s.size();
    //     vector<vector<bool>> dp(n+1,vector<bool>(n+1,0));

    //     dp[n][n]=1;

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=n-1;j>0;j--){
                
    //             if( compare(s.substr(i,j-i+1), wordDict) ){
    //                 if(dp[j+1][j+1]) return true;
    //             }
    //             dp[i][j] = dp[i][j+1];
    //         }
    //     }
    //     return dp[0][0];
    // }
};