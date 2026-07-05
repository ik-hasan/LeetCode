class Solution {
public:

    bool solve(vector<vector<int>>& mat,int row,int col){
        for(int i = 0;i<mat.size();i++){
            if(i==row) continue;
            else if(mat[i][col]==1) return false;
        }
        for(int i = 0;i<mat[0].size();i++){
            if(i==col) continue;
            else if(mat[row][i]==1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        
        int ans = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    bool res = solve(mat,i,j);
                    if(res) ans++;
                }
            }
        }
        return ans;
    }
};