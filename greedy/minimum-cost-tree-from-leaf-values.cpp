class Solution {
public:
    //RECURSION WITH TLE
    // int solveRec(vector<int>& arr, map< pair<int,int>,int> maxi, int s, int e){
    //     if(s>=e) return 0;

    //     int ans = INT_MAX;
    //     for(int i=s;i<e;i++){
    //         int leftRangeKaMax = maxi[{s,i}];
    //         int rightRangeKaMax = maxi[{i+1,e}];
            
    //         int NonLeafValue = leftRangeKaMax * rightRangeKaMax;

    //         ans = min(ans , NonLeafValue + solveRec(arr,maxi,s,i) + solveRec(arr,maxi,i+1,e));
    //     }
    //     return ans;
    // }
    // int mctFromLeafValues(vector<int>& arr) {
    //     map< pair<int,int> , int > maxi;
    //     int n = arr.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(i==j){
    //                 maxi[{i,j}]=arr[i];
    //             }
    //             else{
    //                 maxi[{i,j}] = max( maxi[{i,j-1}] , arr[j] );
    //             }
    //         }
    //     }

    //     return solveRec(arr,maxi,0,n-1);
    // }



    //MEMOIZATION 
    // int solveMem(vector<int>& arr, map< pair<int,int>,int> &maxi, int s, int e, vector<vector<int>> &dp){
    //     if(s>=e) return 0;
    //     if(dp[s][e] != -1) return dp[s][e];
    //     int ans = INT_MAX;
    //     for(int i=s;i<e;i++){
    //         int leftRangeKaMax = maxi[{s,i}];
    //         int rightRangeKaMax = maxi[{i+1,e}];
            
    //         int NonLeafValue = leftRangeKaMax * rightRangeKaMax;
    //         ans = min(ans , NonLeafValue + solveMem(arr,maxi,s,i,dp) + solveMem(arr,maxi,i+1,e,dp));
    //     }
    //     dp[s][e]=ans;
    //     return dp[s][e];
    // }
    // int mctFromLeafValues(vector<int>& arr) {
    //     map< pair<int,int> , int > maxi;
    //     int n = arr.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(i==j){
    //                 maxi[{i,j}]=arr[i];
    //             }
    //             else{
    //                 maxi[{i,j}] = max( maxi[{i,j-1}] , arr[j] );
    //             }
    //         }
    //     }

    //     return solveMem(arr,maxi,0,n-1,dp);
    // }



    //TABULATION
    int mctFromLeafValues(vector<int>& arr) {
        map< pair<int,int> , int > maxi;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j){
                    maxi[{i,j}]=arr[i];
                }
                else{
                    maxi[{i,j}] = max( maxi[{i,j-1}] , arr[j] );
                }
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int s = 0,e=n-1;
        //s->0 to n-1
        //e->n-1 to 0
        for(int S=n-1;S>=0;S--){
            for(int E=0;E<=n-1;E++){
                if(S >= E) continue;
                int ans = INT_MAX;
                for(int i=S;i<E;i++){
                    int leftRangeKaMax = maxi[{S,i}];
                    int rightRangeKaMax = maxi[{i+1,E}];
                    
                    int NonLeafValue = leftRangeKaMax * rightRangeKaMax;
                    ans = min(ans , NonLeafValue + dp[S][i]+ dp[i+1][E]);
                }
                dp[S][E]=ans;
            }
        }
        return dp[0][n-1];
        // return solveMem(arr,maxi,0,n-1,dp);
    }
};