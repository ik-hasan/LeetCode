class Solution {
public:

    bool checkRule(vector<int> e1, vector<int> e2){
        if(e1[0] < e2[0] && e1[1] < e2[1]){
            return true;
        }
        else{
            return false;
        }
    }


    //REC SOLN WITH TLE
    // int solve(vector<vector<int>>& envelopes, int curr,int prev){
    //     if(curr >= envelopes.size()) return 0;
    //     int inc = 0;
    //     if( prev==-1 || checkRule (envelopes[prev],envelopes[curr]) ){
    //         inc = 1 + solve(envelopes, curr+1, curr);
    //     }
    //     int exc = solve(envelopes, curr+1, prev);

    //     return max(inc,exc);
    // }

    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     sort(envelopes.begin(),envelopes.end());
    //     return solve(envelopes,0,-1);
    // }


    //MEMOIZATION
    // int solveDP(vector<vector<int>>& envelopes, int curr,int prev,vector<vector<int>> &dp_arr){

    //     if(curr >= envelopes.size()) return 0;

    //     //step-3 check if ans already exist in dp_arr
    //     if(dp_arr[curr][prev+1] != -1){
    //         return dp_arr[curr][prev+1];
    //     }

    //     int inc = 0;
    //     if( prev==-1 || checkRule (envelopes[prev],envelopes[curr]) ){
    //         inc = 1 + solveDP(envelopes, curr+1, curr,dp_arr);
    //     }
    //     int exc = solveDP(envelopes, curr+1, prev,dp_arr);


    //     //step-2 store rec ans in dp_arr and return
    //     dp_arr[curr][prev+1] = max(inc,exc);
    //     return dp_arr[curr][prev+1];
    // }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     sort(envelopes.begin(),envelopes.end());

    //     //step-1 create and pass dp_arr
    //     int n = envelopes.size();
    //     vector<vector<int>> dp_arr (n+1,vector<int> (n+1,-1));
    //     return solveDP(envelopes,0,-1,dp_arr);
    // }


    //YE QUESTION SIMILIAR TO CUBOIDS H LEETCODE 1691 WHI SE YE SPACE OPTIMIZATION UTHA LIYA. TOP-DWN, TABULATION,SPACEOPTIMIZATION-1 FIR SPACE OPTIMAZTION 2 AISE LINE SE SOLN LIKHTE ISKE TB USKE BAAD HM SPACE OPTIMIZATION-2 PR PHOCH PAATE.


    //SPACE OPTIMIZATION
    // int maxEnvelopes(vector<vector<int>>& envelopes) {

    //     sort(envelopes.begin(),envelopes.end());

    //     int n = envelopes.size();

    //     vector<int> next(n+2,0);
    //     vector<int> c(n+2,0);

    //     //curr->0 to n
    //     //prev->-1 to curr jaega -1 to n nhi
    //     for(int curr=n-1; curr>=0; curr--){
    //         for(int prev=curr-1; prev>=-1; prev--){
    //             int inc = 0;
    //             if( prev == -1 || checkRule (envelopes[prev], envelopes[curr]) ) {
    //                 inc = 1 + next[curr+1];
    //             }
    //             int exc = next[prev+1];

    //             c[prev+1] = max(inc,exc);
    //         }
    //         next = c;
    //     }
    //     return c[0];
    // }

    

    //SPACE OPTIMIZATION 2
    // int maxEnvelopes(vector<vector<int>>& envelopes) {

    //     sort(envelopes.begin(),envelopes.end());

    //     int n = envelopes.size();
    //     vector<int> c(n+2,0);

    //     for(int curr=n-1; curr>=0; curr--){
    //         for(int prev=curr-1; prev>=-1; prev--){
    //             int inc = 0;
    //             if( prev == -1 || checkRule (envelopes[prev], envelopes[curr]) ) {
    //                 inc = 1 + c[curr+1];
    //             }
    //             int exc = c[prev+1];

    //             c[prev+1] = max(inc,exc);
    //         }
    //         //no shifting single array
    //     }
    //     return c[0];
    // }





    //THIS SOLN COME FROM LIS(LEETCODE-300 ), IT'S A BINARY SEARCH SOLN
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        //sort envelopes by width in increasing & if w[i]==w[j] then sort height in decreasing
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                auto x = lower_bound(ans.begin(),ans.end(),envelopes[i][1]);//it gives the position of just >=nums[i]
                int index = x - ans.begin();//iterator x & interator ans.begin() se index ki value nikal rhe
                ans[index]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};