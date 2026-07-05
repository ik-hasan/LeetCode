class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        grid[i][j]=2;
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
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                    grid[ni][nj]=2;
                    q.push({ni,nj});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
                
            }
        }
        return ans;
    }
};