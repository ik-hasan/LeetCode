class Solution {
public:

    void solveDFS(int i, int j, vector<vector<char>> &grid, map<pair<int,int>,bool> &vis){
        vis[make_pair(i,j)]=true;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(vis[make_pair(ni,nj)]) continue;
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]=='1'){
                solveDFS(ni,nj,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        map<pair<int,int>,bool> vis;

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[make_pair(i,j)] && grid[i][j]=='1'){
                    solveDFS(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};