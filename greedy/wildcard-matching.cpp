class Solution {
public:



//     bool solve(string &s, string& p,int i,int j){

//         // if(p.length()==1 && p[0]=='*') return true;

//         if(j==p.length() && i<s.length()) return false;

//         if( ( i==s.length() && j==p.length() )) return true;

//         if(i==s.length()) {
//             for(int k = j; k<p.length();k++){
//                 if(p[k]!='*'){
//                     return false;
//                 }
//             }
//             return true;
//         }

//         if(s[i]==p[j] || p[j]=='?') return solve(s,p,i+1,j+1);

//         // if(p[j]!='*' && s[i]!=p[j]) return false;

//         bool ans = false;
//         if(p[j]=='*'){
//             ans = solve(s,p,i+1,j) || solve(s,p,i,j+1);
//         }
//         return ans;
//     }
//     bool isMatch(string s, string p) {
//         return solve(s,p,0,0);
//     }




//     //DP SOLN OF ABOVE CODE
    bool solveDP(string &s, string& p,int i,int j,vector<vector<int>> &dp_arr){

        // if(p.length()==1 && p[0]=='*') return true;

        if(j==p.length() && i<s.length()) return false;

        if( ( i==s.length() && j==p.length() )) return true;

        if(i==s.length()) {
            for(int k = j; k<p.length();k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        //step-3
        if(dp_arr[i][j] != -1){
            return dp_arr[i][j];
        }

        if(s[i]==p[j] || p[j]=='?') return solveDP(s,p,i+1,j+1,dp_arr);

        bool ans = false;
        if(p[j]=='*'){
            ans = solveDP(s,p,i+1,j,dp_arr) || solveDP(s,p,i,j+1,dp_arr);
        }

        //step-2
        dp_arr[i][j]=ans;
        return dp_arr[i][j];
    }
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        //STEP-1
        vector<vector<int>> dp_arr(n+1,vector<int> (m+1,-1));
        return solveDP(s,p,0,0,dp_arr);
    }
};





