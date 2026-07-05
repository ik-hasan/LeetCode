class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;//first = x coordinate of rotten orange, second = y coordinate of rotten orange
        int n = grid.size();
        int m = grid[0].size();
        int rottenOranges = 0, freshOranges = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    rottenOranges++;
                }
                else if(grid[i][j]==1) freshOranges++;
            }
        }

        if(freshOranges==0) return 0;
        if(rottenOranges==0) return -1;

        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            bool isRotten = false;
            for(int i =0; i<size;i++){
                auto front = q.front();
                int row = front.first;
                int col = front.second;
                q.pop();
                for(auto dir:directions){
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    if(newRow<n && newRow>=0 && newCol<m && newCol>=0 && grid[newRow][newCol]==1){
                        freshOranges--;
                        grid[newRow][newCol]=2;
                        q.push({newRow,newCol});
                        isRotten = true;
                    }
                }
            }
            if(isRotten) minutes++;
        }
        if(freshOranges>0) return -1;
        return minutes;
    }
};