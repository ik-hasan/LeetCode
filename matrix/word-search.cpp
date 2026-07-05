class Solution {
public:

    bool solve(vector<vector<char>>& board, string &word,map<pair<int,int>,bool> &visited,int i,int j,int k){
        if(k == word.size()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[{i,j}] || board[i][j] != word[k])
            return false;

        visited[{i,j}]  = true;

        if(solve(board,word,visited,i,j+1,k+1)) return true;
        if(solve(board,word,visited,i,j-1,k+1)) return true;
        if(solve(board,word,visited,i+1,j,k+1)) return true;
        if(solve(board,word,visited,i-1,j,k+1)) return true;

        visited[{i,j}] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        map<pair<int,int>,bool> visited;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                bool ans = solve(board,word,visited,i,j,0);
                if(ans) return true;
            }
        }
        return false;
    }
};