class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {


        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> time(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        //row,col

        for(auto it : sources){
            int r = it[0];
            int c = it[1];
            int color = it[2];
            grid[r][c] = color;
            q.push({r,c});//time = 0 bcz ye sb already colored h
        }

        vector<int> rDir {-1,1,0,0};
        vector<int> cDir {0,0,-1,1};

        //MULTI BFS
        while(!q.empty()){
            int sz = q.size();
            map<pair<int,int>,int> best;
            
            for(int i=0;i<sz;i++){
                auto[r,c] = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nr = r + rDir[i];
                    int nc = c + cDir[i];
                    if(nr<0 || nr>=n || nc<0 ||nc>=m) continue;

                    if(grid[nr][nc]==0){
                        best[{nr,nc}] = max(best[{nr,nc}],grid[r][c]);
                    }
                }
            }
            for(auto &it:best){
                int r = it.first.first;
                int c = it.first.second;
                int color = it.second;
                grid[r][c]=color;
                q.push({r,c});
            }
        }

        return grid;
    }
};