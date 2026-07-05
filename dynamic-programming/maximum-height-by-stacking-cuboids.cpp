class Solution {
public:

    //ek ke ooper ek cuboids rkhne ke rule
    bool checkRule(vector<int> c1,vector<int> c2){
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]){
            return true;
        }
        else{
            return false;
        }
    }

    //REC SOLN WITH TLE
    // int solve(vector<vector<int>>& cuboids,int curr,int prev){
    //     if(curr >= cuboids.size()) return 0;
    //     int inc = 0;
    //     if( prev == -1 || checkRule (cuboids[prev], cuboids[curr]) ) {
    //         inc = cuboids[curr][2] + solve(cuboids,curr+1,curr);
    //     }
    //     int exc = solve(cuboids,curr+1,prev);

    //     return max(inc,exc);
    // }
    // int maxHeight(vector<vector<int>>& cuboids) {
    //     for(auto &i:cuboids){
    //         sort(i.begin(),i.end());
    //     }
    //     sort(cuboids.begin(),cuboids.end());
    //     return solve(cuboids,0,-1);
    // }


    //DP SOLN OF ABOVE CODE
    // int solveDP(vector<vector<int>>& cuboids,int curr,int prev,vector<vector<int>> &dp_arr){
    //     if(curr >= cuboids.size()) return 0;

    //     //step-3 check if ans aready exist in dp_arr
    //     if(dp_arr[curr][prev+1] != -1){  //starting me prev=-1 h to inaccessible ho jaega isliye hr jgh prev ko prev+1 kr diya
    //         return dp_arr[curr][prev+1];
    //     }

    //     int inc = 0;
    //     if( prev == -1 || checkRule (cuboids[prev], cuboids[curr]) ) {
    //         inc = cuboids[curr][2] + solveDP(cuboids,curr+1,curr,dp_arr);
    //     }
    //     int exc = solveDP(cuboids,curr+1,prev,dp_arr);


    //     //step-2 store and return
    //     dp_arr[curr][prev+1] = max(inc,exc);
    //     return dp_arr[curr][prev+1];
    // }

    // int maxHeight(vector<vector<int>>& cuboids) {
    //     for(auto &i:cuboids){
    //         sort(i.begin(),i.end());
    //     }
    //     sort(cuboids.begin(),cuboids.end());

    //     int n = cuboids.size();

    //     //step-1 creating dp_arr and pass
    //     vector<vector<int>> dp_arr (n+1,vector<int> (n+1,-1));//hm prev ko dp_arr me prev+1 se access kr rhe h isliye hme n+1 ko n+2 krna chahiye lekin n+1 se kam chal ja rha h to koi dikkat nhi h agr n+1 se kam nhi chalta to hm n+2 krte.
    //     return solveDP(cuboids,0,-1,dp_arr);
    // }



    //TABULATION
    // int maxHeight(vector<vector<int>>& cuboids) {
    //     for(auto &i:cuboids){
    //         sort(i.begin(),i.end());
    //     }
    //     sort(cuboids.begin(),cuboids.end());

    //     int n = cuboids.size();

    //     vector<vector<int>> dp (n+2,vector<int> (n+2,0));

    //     //curr->0 to n
    //     //prev->-1 to curr jaega -1 to n nhi
    //     for(int curr=n-1; curr>=0; curr--){
    //         for(int prev=curr-1; prev>=-1; prev--){
    //             int inc = 0;
    //             if( prev == -1 || checkRule (cuboids[prev], cuboids[curr]) ) {
    //                 inc = cuboids[curr][2] + dp[curr+1][curr+1];
    //             }
    //             int exc = dp[curr+1][prev+1];

    //             dp[curr][prev+1] = max(inc,exc);
    //         }
    //     }
    //     return dp[0][0];
    // }



    //SPACE OPTIMIZATION
    // int maxHeight(vector<vector<int>>& cuboids) {
    //     for(auto &i:cuboids){
    //         sort(i.begin(),i.end());
    //     }
    //     sort(cuboids.begin(),cuboids.end());

    //     int n = cuboids.size();

    //     // vector<vector<int>> dp (n+2,vector<int> (n+2,0));
    //     vector<int> next(n+2,0);
    //     vector<int> c(n+2,0);

    //     //curr->0 to n
    //     //prev->-1 to curr jaega -1 to n nhi
    //     for(int curr=n-1; curr>=0; curr--){
    //         for(int prev=curr-1; prev>=-1; prev--){
    //             int inc = 0;
    //             if( prev == -1 || checkRule (cuboids[prev], cuboids[curr]) ) {
    //                 inc = cuboids[curr][2] + next[curr+1];
    //             }
    //             int exc = next[prev+1];

    //             c[prev+1] = max(inc,exc);
    //         }
    //         //yhi hgg deta hu bar bar shifting me bar bar bhul jata hu shift krna
    //         next = c;
    //     }
    //     return c[0];
    // }



    //SPACE OPTIMIZATION 2
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i:cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());

        int n = cuboids.size();

        // vector<vector<int>> dp (n+2,vector<int> (n+2,0));
        // vector<int> next(n+2,0);
        vector<int> c(n+2,0);

        //curr->0 to n
        //prev->-1 to curr jaega -1 to n nhi
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int inc = 0;
                if( prev == -1 || checkRule (cuboids[prev], cuboids[curr]) ) {
                    inc = cuboids[curr][2] + c[curr+1];
                }
                int exc = c[prev+1];

                c[prev+1] = max(inc,exc);
            }
            //yhi hgg deta hu bar bar shifting me bar bar bhul jata hu shift krna
            // next = c;
        }
        return c[0];
    }
};