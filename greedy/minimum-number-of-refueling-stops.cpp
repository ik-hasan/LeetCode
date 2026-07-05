// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
//         int ans = 0;
//         priority_queue<pair<int,int>,<vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         //first = position, second = station

//         for(auto station:stations){
//             pq.push( {station[0],station[1]} );
//         }

//         while(!pq.empty()){
//             auto front = pq.top();
//             pq.pop();

//             //case-1 phle station tk hi nhi phoch paya jo least dist pr tha
//             if(startFuel < front.first) return -1;

//             //case-2 empty fuel ke sath station pr phoch gya
//             else if(startFuel == front.first){
//                 ans++;
//                 target = target-startFuel;
//                 if(target <=0 ) return ans;
//                 startFuel = front.second;
//                 if(startFuel >= target) return ans;
//             }

//             //case-3 fuel car me h aur fir station pr phoch gya
//             else if(startFuel > front.first){
                
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        priority_queue<int> pq; // max heap for fuel
        int fuel = startFuel;
        int ans = 0,i=0;

        while (fuel < target) {

            // jitne stations reachable hain unka fuel max heap me daalo
            while (i < stations.size() && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                i++;
            }

            // agar koi reachable station hi nahi to return -1
            if (pq.empty()) return -1;

            // sabse bada fuel lo
            fuel += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};


//core intution - reachable stations me jis station me maxm fuel h us station pr refuel krenge