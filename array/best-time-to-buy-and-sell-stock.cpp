// class Solution {
// public:

//     int big(int index,vector<int>& prices){
//         int ans = INT_MIN;
//         for(int i=index;i<prices.size();i++){
//             ans = max(ans,prices[i]);
//         }
//         return ans;
//     }
//     int maxProfit(vector<int>& prices) {
        
//         int ans = INT_MIN;
//         for(int i=0;i<prices.size()-1;i++){
//             int val = prices[i];
//             int greatest = big(i+1,prices);
//             int currAns = greatest - val;
//             if(currAns < 0) continue;
//             ans = max(ans,currAns);
//         }
//         return (ans == INT_MIN) ? 0 : ans;
//     }
// };
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int ans = 0;
        int mini = prices[0];
        for(int i=1;i<prices.size();i++){
            int profit = prices[i]-mini;
            ans = max(ans,profit);
            mini = min(mini,prices[i]);
        }
        return ans;

    }
};