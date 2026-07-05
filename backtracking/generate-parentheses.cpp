
//SOLN-1 PURE REC
// class Solution {
// public:
//     void solve(int open, int close, int n, vector<string>& ans,string output){
//         if(close+open == 2*n){
//             ans.push_back(output);
//             return;
//         }

//         if(open<n){
//             solve(open+1,close,n,ans,output+'(');
//         }
//         if(close<open){
//             solve(open,close+1,n,ans,output+')');
//         }
//         return;
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         string output="";
//         int open=0,close=0;
//         solve(open,close,n,ans,output);
//         return ans;
//     }
// };




// //SOLN-2 with backtracking
// class Solution {
// public:
//     void solve(int open, int close, int n, vector<string>& ans,string &output){
//         if(close+open == 2*n){
//             ans.push_back(output);
//             return;
//         }

//         if(open<n){
//             output.push_back('(');
//             solve(open+1,close,n,ans,output);
//             output.pop_back();
//         }
//         if(close<open){
//             output.push_back(')');
//             solve(open,close+1,n,ans,output);
//             output.pop_back();
//         }
//         return;
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         string output="";
//         int open=0,close=0;
//         solve(open,close,n,ans,output);
//         return ans;
//     }
// };


























class Solution {
public:

    void solve(int n, string s, int open, int close, vector<string> &ans){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(n,s,open+1,close,ans);
            s.pop_back();
        }
        if(open > close && close < n){
            s.push_back(')');
            solve(n,s,open,close+1,ans);
            s.pop_back();
        }
        return;

    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int open = 0;
        int close = 0;
        vector<string> ans ;
        solve(n,s,open,close,ans);
        return ans;
    }
};























