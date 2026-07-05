class Solution {
public:

    //LOGIC SHI H AB DP LGA KR ACCEPT KRWA LUNGA
    // int solve(vector<int>& days, vector<int>& costs,int index){
    //     if(index>=days.size()) return 0;

    //     int for7=index,for30=index;

    //     int oneDayPassCost = costs[0]+solve(days,costs,index+1);

    //     while(for7<days.size() && days[for7]<days[index]+7){
    //         for7++;
    //     }
    //     int sevenDayPassCost = costs[1]+solve(days,costs,for7);
        
    //     while(for30<days.size() && days[for30]<days[index]+30){
    //         for30++;
    //     }
    //     int thirtyDayPassCost = costs[2]+solve(days,costs,for30);

    //     return min(oneDayPassCost,min(sevenDayPassCost,thirtyDayPassCost));
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     return solve(days,costs,0);
    // }



    int solveDP(vector<int>& days, vector<int>& costs,int index,vector<int> &dp_arr){
        if(index>=days.size()) return 0;

        //step-3
        if(dp_arr[index]!=-1){
            return dp_arr[index];
        }

        int for7=index,for30=index;

        int oneDayPassCost = costs[0]+solveDP(days,costs,index+1,dp_arr);

        while(for7<days.size() && days[for7]<days[index]+7){
            for7++;
        }
        int sevenDayPassCost = costs[1]+solveDP(days,costs,for7,dp_arr);
        
        while(for30<days.size() && days[for30]<days[index]+30){
            for30++;
        }
        int thirtyDayPassCost = costs[2]+solveDP(days,costs,for30,dp_arr);


        //step-2
        dp_arr[index]=min(oneDayPassCost,min(sevenDayPassCost,thirtyDayPassCost));;
        return dp_arr[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        vector<int> dp_arr(n+1,-1);
        return solveDP(days,costs,0,dp_arr);
    }
};