class Solution {
public:

    pair<int,int> solve(vector<vector<char>>& mat,int i, int j, int alwaysI, int alwaysJ){
        //base case
        if(i+1>=mat.size() || j+1>=mat[0].size() || mat[i+1][j+1] != '1') return {i,j};

        int newI = i+1;
        int newJ = j+1;
        while(newI>=alwaysI){
            if(mat[newI][newJ] != '1') return {i,j};
            newI--;
        }

        newI = i+1;
        newJ = j+1;
        while(newJ>=alwaysJ){
            if(mat[newI][newJ] != '1') return {i,j};
            newJ--;
        }

        return solve(mat,i+1,j+1,alwaysI,alwaysJ);
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int ans = INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){

                //pruning - un cells ko skip karna jahan se current best answer se bada square possible hi nahi hai.
                int maxPossible = min(matrix.size()-i,matrix[0].size()-j);
                if(maxPossible*maxPossible <= ans) continue;  

                if(matrix[i][j]=='1' ){
                    auto res = solve(matrix,i,j,i,j);
                    int side = res.first - i + 1;
                    ans = max(ans,side*side);
                }
            }
        }
        return (ans==INT_MIN ? 0 : ans);
    }
};





// class Solution {
// public: 
//     int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
//         //base case
//         if(i >= row || j>= col) {
//             return 0;
//         }
//         //explore all 3 directions
//         int right = solve(matrix, i, j+1, row, col, maxi);
//         int diagnol = solve(matrix, i+1, j+1, row, col, maxi);
//         int down = solve(matrix, i+1, j, row, col, maxi);

//         if(matrix[i][j] == '1') {
//             int ans = 1 + min(right, min(down, diagnol));
//             //ye important hai 
//             maxi = max(maxi, ans);
//             return ans;
//         }
//         else {
//             return 0;
//         }
//      }
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int i = 0; 
//         int j = 0;
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int maxi = 0;
//         int ans = solve(matrix, i, j, row, col, maxi) ;
//         return maxi*maxi;
//     }
// };