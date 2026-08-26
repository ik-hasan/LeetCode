// class Solution {
// public:

//     string solve(int i, int j, string &s1, string &s2, vector<vector<string>> &dp){
//         if(i<=s1.length()-1 && j>s2.length()-1) return s1.substr(i,s1.length()-i);
//         if(j<=s2.length()-1 && i>s1.length()-1) return s2.substr(j,s2.length()-j);
//         if(i>=s1.length() || j>=s2.length()) return "";

//         if(dp[i][j]!= "$") return dp[i][j];
//         if(s1[i]==s2[j]) return dp[i][j] = s1[i] + solve(i+1,j+1,s1,s2,dp);

//         string a = s1[i] + solve(i+1,j,s1,s2,dp);
//         string b = s2[j] + solve(i,j+1,s1,s2,dp);

//         return dp[i][j] = (a.length()>b.length()) ? b : a;
//     }
//     string shortestCommonSupersequence(string str1, string str2) {
//         vector<vector<string>> dp(str1.length(),vector<string>(str2.length(),"$"));
//         return solve(0,0,str1,str2,dp);
//     }
// };


class Solution {
public:

    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        
        if(i >= s1.length())
            return s2.length() - j;
        
        if(j >= s2.length())
            return s1.length() - i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, s1, s2, dp);
        
        return dp[i][j] = 1 + min(
            solve(i+1, j, s1, s2, dp),
            solve(i, j+1, s1, s2, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // solve(0, 0, str1, str2, dp);
        
        string ans = "";
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m) {
            
            if(str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            
            else if(solve(i+1, j, str1, str2, dp) 
                    <= solve(i, j+1, str1, str2, dp)) {
                
                ans += str1[i];
                i++;
            }
            
            else {
                ans += str2[j];
                j++;
            }
        }
        
        while(i < n) {
            ans += str1[i];
            i++;
        }
        
        while(j < m) {
            ans += str2[j];
            j++;
        }
        
        return ans;
    }
};