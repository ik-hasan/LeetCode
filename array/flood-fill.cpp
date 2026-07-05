class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int target = image[sr][sc];
        if(target == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;

            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 && newX<image.size() && newY>=0 && newY<image[0].size() && image[newX][newY]==target){
                    image[newX][newY] = color;
                    q.push({newX,newY});
                }
            }
        }
        return image;
    }
};