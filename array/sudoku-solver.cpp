class Solution {
public:
    bool isSafe(int row,int col, char c,vector<vector<char>>& board){
        for(int k=0;k<9;k++){
            if(board[row][k]==c) return false;
        }
        for(int k=0;k<9;k++){
            if(board[k][col]==c) return false;
        }
        for(int k=0;k<9;k++){
            if(board[ 3*(row/3) + k/3 ][ 3*(col/3) + k%3]==c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        //base case
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch = '1';ch<='9';ch++){
                        if(isSafe(i,j,ch,board)){
                            board[i][j]=ch;
                            if(solve(board)) return true;//agr true ho gya to fir backtrack nhi krenge
                            board[i][j]='.';//agr true nhi aaya mtlb hmne lasttime glt number daal diya h, iskiye backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};