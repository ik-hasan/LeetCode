class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        map<pair<int,int>,bool> vis;
        vector<int> temp;

        int m = grid.size();
        int n = grid[0].size();
        int layer = min(m,n)/2;

        for(int i=0;i<layer;i++){

            vector<int> temp;
            int top =  i;
            int left = i;
            int bottom = m-i-1;
            int right = n-i-1;

            //top line
            for(int j=left;j<right;j++){
                temp.push_back(grid[top][j]);
            }

            //right line
            for(int j=top;j<bottom;j++){
                temp.push_back(grid[j][right]);
            }

            //bottom line
            for(int j = right;j>left;j--){
                temp.push_back(grid[bottom][j]);
            }

            //left line
            for(int j=bottom;j>top;j--){
                temp.push_back(grid[j][left]);
            }

            int len = temp.size();
            int rotation = k % len;

            //1st way of getting rotated elem
            vector<int> rotate(len);
            for(int j=0;j<len;j++){
                rotate[j] = temp[(rotation + j) % len];
            }
            int index = 0;


            //2nd way of getting rotated elem
            // vector<int> rotate = temp;
            // for(int i=0;i<len;i++){
            //     rotate.push_back(temp[i]);
            // }
            // int index = rotation;


            // fill top line
            for(int j=left;j<right;j++){
                grid[top][j] = rotate[index++];
            }

            //fill right line
            for(int j=top;j<bottom;j++){
                grid[j][right] = rotate[index++];
            }

            //fill bottom line
            for(int j = right;j>left;j--){
                grid[bottom][j] = rotate[index++];
            }

            //fill left line
            for(int j=bottom;j>top;j--){
                grid[j][left] = rotate[index++];
            }
        }
        return grid;
    }
};