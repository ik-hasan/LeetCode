// class Solution {
// public:

//     int solve(int i, int j, string &s1, string &s2){
//         if(j>=s2.length()) return s1.length()-i;
//         if(i>=s1.length()) return s2.length()-j;
//         if(i>=s1.length() && j>=s2.length()) return 0;

//         if(s1[i]==s2[j]) return solve(i+1,j+1,s1,s2);

//         return 1 + min({solve(i+1,j,s1,s2),solve(i+1,j+1,s1,s2),solve(i,j+1,s1,s2)});
//     }
//     int minDistance(string word1, string word2) {
//         return solve(0,0,word1,word2);
//     }
// };



class Solution {
public:
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>> &dp){
        if(i>=word1.length() && j>=word2.length()) return 0;
        if(i>=word1.length()) return word2.length()-j;
        if(j>=word2.length()) return word1.length()-i;

        if(dp[i][j] != -1) return dp[i][j]; 
     
        int ans = 0;
        if(word1[i]==word2[j]) return solve(word1,word2,i+1,j+1,dp);
        else{
            //replace
            int replace = 1 + solve(word1,word2,i+1,j+1,dp);
            //insert
            int insert = 1 + solve(word1,word2,i+1,j,dp);
            //delete
            int del = 1 + solve(word1,word2,i,j+1,dp);
            ans = min(replace,min(insert,del));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};