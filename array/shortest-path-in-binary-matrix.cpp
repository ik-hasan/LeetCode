class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] != 0 || grid[row - 1][row - 1] != 0) return -1;
        
        //simple bfs lga kr shortest path nikalo bcz sbka wt 1 consider krna h

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        grid[0][0] = 1;//work as visited

        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto front = q.front();
            int nodeDist = front.first;
            int nodeX = front.second.first;
            int nodeY = front.second.second;
            if(nodeX==row-1 && nodeY==row-1) return nodeDist;
            q.pop();

            for(int i=0;i<dx.size();i++){
                int nx = nodeX+dx[i];
                int ny = nodeY+dy[i];
                if(nx < row && ny < col && nx >=0 && ny >=0 && grid[nx][ny]== 0 ){
                    grid[nx][ny] = 1;
                    q.push({nodeDist+1,{nx,ny}});
                }
            }
        }

        return -1;
    }
};