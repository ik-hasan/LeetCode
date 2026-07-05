// class Solution {
// public:
//     int totalNQueens(int n) {
        
//     }
// };



class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperDiagnolCheck;
    unordered_map<int,bool> lowerDiagnolCheck;

    bool isSafe(int row,int col,vector<vector<char>> &board){
        if(rowCheck[row]==true) return false;
        if(upperDiagnolCheck[col-row]==true) return false;
        if(lowerDiagnolCheck[row+col]==true) return false;
        return true;
    }

    void makeAns( vector<vector<char>> &board,vector<vector<string>> &ans, int n ){

        vector<string> temp;
        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output += board[i][j];
            }
            temp.push_back(output);
        }
        ans.push_back(temp);

    }
    void solve(int n, int col, vector<vector<char>> &board,vector<vector<string>> &ans){
        if(col >= n){
            makeAns(board,ans,n);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board)){

                board[row][col]='Q';
                rowCheck[row]=true;
                upperDiagnolCheck[col-row]=true;
                lowerDiagnolCheck[row+col]=true;

                solve(n,col+1,board,ans);
    
                ///backtrack
                board[row][col]='.';
                rowCheck[row]=false;
                upperDiagnolCheck[col-row]=false;
                lowerDiagnolCheck[row+col]=false;
            }
        }
        return;
    }
    int totalNQueens(int n) {

        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int col = 0;
        solve(n,col,board,ans);
        return ans.size();

    }
};