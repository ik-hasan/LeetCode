class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        int row = h.size(), col = h[0].size();

        pq.push({0,{0,0}});

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};

        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));

        diff[0][0] = 0;

        while(!pq.empty()){
            auto front = pq.top();
            int effort = front.first;
            int x = front.second.first;
            int y = front.second.second;
            if(x==row-1 && y==col-1) return effort;
            pq.pop();

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx<row && nx>=0 && ny<col && ny>=0 ){
                    int newDiff = max(effort,abs(h[nx][ny]-h[x][y]));
                    int oldDiff = diff[nx][ny];
                    if(oldDiff>newDiff){
                        diff[nx][ny] = newDiff;
                        pq.push({newDiff,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};