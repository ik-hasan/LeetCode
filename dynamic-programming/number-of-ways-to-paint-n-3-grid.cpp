//PURE LOGIC BASED BRUTE FORCE

// class Solution {
// public:

//     long long modulo = 1000000007;

//     bool isSafe(int color,int i,int j, vector<vector<int>> &board){
//         if(i > 0 && board[i-1][j]==color) return false;
//         if(j > 0 && board[i][j-1]==color) return false;
//         return true;
//     }

//     void solve(vector<vector<int>> &board,int &ans,int &n,int i,int j){
//         if(i==n){
//             ans++;
//             return;
//         }
        
//         for(int color=0;color<3;color++){
//             if(isSafe(color,i,j,board)){
//                 board[i][j]=color;
//                 if(j==2){
//                     solve(board,ans,n,i+1,0);
//                 }
//                 else{
//                     solve(board,ans,n,i,j+1);
//                 }
//                 board[i][j]=-1;//backtracking
//             }
//         }
//         return;
//     }
//     int numOfWays(int n) {
//         int ans=0;
//         vector<vector<int>> board(n,vector<int>(3,-1));
//         solve(board,ans,n,0,0);
//         return ans%modulo;
//     }
// };


//SOLN-2 PATTERN RECOGNIZATION (SOLUTIONS SECTION ME NAMAN KE SOLN SE SMJHA)
class Solution {
public:
    int numOfWays(int n) {
        long long modulo = 1000000007;

        long long patternA = 6;//ABA
        long long patternB = 6;//ABC

        for(int i=2;i<=n;i++){

            long long newPatternA = ( patternA*3 + patternB*2 )%modulo;
            long long newPatternB = ( patternA*2 + patternB*2 ) % modulo;
            patternA = newPatternA;
            patternB = newPatternB;
        }

        return (patternA + patternB)%modulo;
    }
};