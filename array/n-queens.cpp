class Solution {
public:

    bool isSafe(int i,int j,int n,vector<string>& ans){
        int newI = i;
        int newJ = j;
        //left row check
        while(newJ>=0) if(ans[newI][newJ--]=='Q') return false;

        //upper left diagnol check
        newI=i;newJ=j;
        while(newI>=0 && newJ>=0) if(ans[newI--][newJ--]=='Q') return false;

        //lower left diagnol check
        newI=i;newJ=j;
        while(newI<n && newJ>=0) if(ans[newI++][newJ--]=='Q') return false;

        return true;
    }   
    void solve(int n, int col, vector<vector<string>> &ans, vector<string> temp){
        // base case
        if(col==n){
            ans.push_back(temp);
            return;
        }

        for(int row = 0;row<n;row++){
            if(isSafe(row,col,n,temp)){
                temp[row][col]='Q';
                solve(n,col+1,ans,temp);
                temp[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        solve(n,0,ans,temp);
        return ans;
    }
};


// class Solution {
// public:

//     bool isSafe(int row,int col,vector<string> &board,int n){

//         int r=row,c=col;

//         // check column
//         while(r>=0){
//             if(board[r][c]=='Q') return false;
//             r--;
//         }

//         r=row; c=col;

//         // upper left diagonal
//         while(r>=0 && c>=0){
//             if(board[r][c]=='Q') return false;
//             r--; c--;
//         }

//         r=row; c=col;

//         // upper right diagonal
//         while(r>=0 && c<n){
//             if(board[r][c]=='Q') return false;
//             r--; c++;
//         }

//         return true;
//     }

//     void solve(int row,int n,vector<string> &board,vector<vector<string>> &ans){

//         if(row==n){
//             ans.push_back(board);
//             return;
//         }

//         for(int col=0;col<n;col++){

//             if(isSafe(row,col,board,n)){
//                 board[row][col]='Q';

//                 solve(row+1,n,board,ans);

//                 board[row][col]='.'; // backtrack
//             }

//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {

//         vector<vector<string>> ans;
//         vector<string> board(n,string(n,'.'));

//         solve(0,n,board,ans);

//         return ans;
//     }
// };