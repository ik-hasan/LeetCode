class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        for(int i=0;i<n;i++){
            int j = i;
            bool flag = true;
            int currTel = gas[j];
            for(int x=i;x<i+n;x++){
                if(currTel<cost[j]){
                    flag= false;
                    i=x;//pruning
                    break;
                }
                if(j+1>=gas.size()) {
                    currTel = currTel-cost[j]+gas[0];
                    j=0;
                    continue;
                }
                currTel = currTel-cost[j]+gas[j+1];
                j++;
            }
            if(j==i && flag) return i;
        }
        return -1;
    }
};




//more optimize
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
//         int balance = 0;
//         int kami = 0;
//         int startIndex = 0;
//         for(int i=0;i<gas.size();i++){
//             balance = balance + gas[i] - cost[i];
//             if(balance < 0){
//                 kami = kami + abs(balance);
//                 balance = 0;
//                 startIndex = i+1;
//             }
//         }
//         return (balance - kami >=0) ? startIndex : -1;
//     }
// };