class Solution {
public:

    bool checkBound(vector<vector<int>>& grid,vector<pair<int,int>> &v){
        int n = grid.size();//row
        int m = grid[0].size();//col
        for(auto &val : v){
            if( val.first<0 || val.first>=n || val.second<0 || val.second>=m) return false;
        }
        return true;
    }

    bool getVertices(vector<vector<int>>& grid,pair<int,int> p,vector<pair<int,int>> &v,int delta){
        v.clear();
        pair<int,int> A(p.first-delta,p.second);
        pair<int,int> B(p.first,p.second+delta);
        pair<int,int> C(p.first+delta,p.second);
        pair<int,int> D(p.first,p.second-delta);
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        v.push_back(D);
        
        if(checkBound(grid,v)) return true;
        return false;
    }

    void getSum(vector<vector<int>>& grid,int cx,int cy, priority_queue<int> &pq){

        pq.push(grid[cx][cy]);
        vector<pair<int,int>> v;
        int delta = 1;

        while(getVertices(grid,{cx,cy},v,delta)){

            pair<int,int> A = v[0];
            pair<int,int> B = v[1];
            pair<int,int> C = v[2];
            pair<int,int> D = v[3];

            int sum = 0;
            sum += grid[A.first][A.second];
            sum += grid[B.first][B.second];
            sum += grid[C.first][C.second];
            sum += grid[D.first][D.second];

            //sum from point A to B
            for(int i = 1; i < (B.first - A.first); ++i){
                sum += grid[A.first + i][A.second + i];
            }

            //sum from point B to C
            for(int i = 1; i < (C.first - B.first); ++i){
                sum += grid[B.first + i][B.second - i];
            }

            // sum from point C to D
            for(int i = 1; i < (C.first - D.first); ++i){
                sum += grid[C.first - i][C.second - i];
            }

            //sum from point D to A
            for(int i = 1; i < (D.first - A.first); ++i){
                sum += grid[D.first - i][D.second + i];
            }
            
            pq.push(sum);
            delta++;
        }

    }

    bool canpush(vector<int>&ans,int &top){
        for(auto &x:ans){
            if(x==top) return false;
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int n = grid.size();//row
        int m = grid[0].size();//col
        priority_queue<int> pq;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //we are calling it for each cell{i,j}
                getSum(grid,i,j,pq);
            }
        }

        vector<int> ans;
        while(!pq.empty() && ans.size()<3){
            int top = pq.top();pq.pop();
            if(canpush(ans,top)){
                ans.push_back(top);
            }
        }
        return ans;
    }
};