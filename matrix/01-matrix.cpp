class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;

            for(int k=0;k<4;k++){
                int nx = dx[k] + i;
                int ny = dy[k] + j;

                if(nx>=0 && nx<row && ny>=0 && ny<col && ans[nx][ny]==-1 ){
                    ans[nx][ny] = ans[i][j] + 1;
                    q.push({nx,ny}); 
                }
            }
        }
        return ans;

    }
};