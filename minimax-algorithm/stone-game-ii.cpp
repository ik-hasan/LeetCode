class Solution {
public:
    // int solve(vector<int>& piles, int index, int m, bool alice){
    //     if(index >= piles.size()) return 0;

    //     int ans = alice ? INT_MIN : INT_MAX;
    //     int total = 0;
    //     for(int x=1; x<=2*m; x++){
    //         if(index+x-1 >= piles.size()) break;
    //         total = total + piles[index+x-1];

    //         if(alice) {
    //             ans = max(ans,total + solve(piles,index+x,max(m,x),!alice));//include, alice ans ko maximize kr rhi h
    //         }
    //         else{
    //             ans = min (ans,solve(piles,index+x,max(m,x),!alice));//exclude, bob alice ke ans ko minimize kr rha h
    //         } 
    //     }
    //     return ans;
    // }
    // int stoneGameII(vector<int>& piles) {
    //     int m = 1;
    //     return solve(piles,0,1,true);
    // }



    //MEMOIZATION 3D DP
    int solve(vector<int>& piles, int index, int m, bool alice,vector<vector<vector<int>>> &dp){
        if(index >= piles.size()) return 0;
        if(dp[index][m][alice] != -1) return dp[index][m][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
        for(int x=1; x<=2*m; x++){
            if(index+x-1 >= piles.size()) break;

            total = total + piles[index+x-1];

            if(alice) {
                ans = max(ans,total + solve(piles,index+x,max(m,x),!alice,dp));
            }
            else{
                ans = min (ans,solve(piles,index+x,max(m,x),!alice,dp));
            } 
        }

        dp[index][m][alice] = ans;
        return dp[index][m][alice];
    }
    int stoneGameII(vector<int>& piles) {
        int m = 1;
        int n = piles.size();
        vector<vector<vector<int>>> dp ( n+1, vector<vector<int>>(n+1,vector<int>(2,-1)) );
        return solve(piles,0,1,true,dp);
    }




    //TABULATION/BOTTOM UP
    // int stoneGameII(vector<int>& piles) {
    //     int m = 1;
    //     int n = piles.size();
    //     vector<vector<vector<int>>> dp ( n+1, vector<vector<int>>(n+1,vector<int>(2,0)) );
        
    //     for(int index = n-1; index>=0; index--){
    //         for(int m = n; m>=1;m--){
    //             for(int alice = 0; alice<=1;alice++){
    //                 int ans = alice ? INT_MIN : INT_MAX;
    //                 int total = 0;
    //                 for(int x=1; x<=2*m; x++){
    //                     if(index+x-1 >= piles.size()) break;

    //                     total = total + piles[index+x-1];

    //                     if(alice) {
    //                         ans = max(ans,total + dp[index+x][max(m,x)][!alice]);
    //                     }
    //                     else{
    //                         ans = min (ans,dp[index+x][max(m,x)][!alice]);
    //                     } 
    //                 }

    //                 dp[index][m][alice] = ans;
    //             }
    //         }
    //     }
    //     return dp[0][1][1];
    // }
};