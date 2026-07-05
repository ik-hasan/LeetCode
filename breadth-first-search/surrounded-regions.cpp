class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]=='O'){
                        board[i][j]='s';
                        q.push({i,j});
                    }

                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){

            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]=='O'){
                    board[ni][nj]='s';
                    q.push({ni,nj});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='s') board[i][j]='O';
            }
        }
                    
    }
};