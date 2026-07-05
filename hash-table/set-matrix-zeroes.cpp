class Solution {
public:

    void setMatrix(vector<vector<int>>& matrix,int i,int j,map<pair<int,int>,bool> &vis){
        int n = matrix.size();
        int m = matrix[0].size();
        int x = i;
        int y = j;
        while(x>=0){
            if( matrix[x][j] == 0){
                x--;
                continue;
            }
            vis[{x,j}] = true;
            matrix[x][j]=0;
            x--;
        }
        x=i;
        while(x<n){
            if( matrix[x][j] == 0) {
                x++;
                continue;
            }
            vis[{x,j}] = true;
            matrix[x][j]=0;
            x++;
        }
        while(y>=0){
            if( matrix[i][y] == 0) {
                y--;
                continue;
            }
            vis[{i,y}] = true;
            matrix[i][y]=0;
            y--;
        }
        y=j;
        while(y<m){
            if( matrix[i][y] == 0) {
                y++;
                continue;
            }
            vis[{i,y}] = true;
            matrix[i][y]=0;
            y++;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        map<pair<int,int>,bool> vis;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0 && !vis[{i,j}]){
                    setMatrix(matrix,i,j,vis);
                }
            }
        }
    }
};