// class Solution {
// public:
//     int minimumEffort(vector<vector<int>>& tasks) {
//         int sum = 0;
//         for(auto &it:tasks){
//             sum += it[1];
//             swap(it[0],it[1]);
//         }
//         sort(tasks.rbegin(),tasks.rend());
//         int n = tasks.size();
//         int maxi = tasks[0][0];

//         int m = sum-maxi;
//         int oldMaxi = maxi;
//         int tempSum = 0;
//         for(int i=0;i<=m;i++){
//             if(i==n) return oldMaxi;
//             if( maxi >= tasks[i][0] ){
//                 maxi -= tasks[i][1];
//                 tempSum += tasks[i][1];
//             }
//             else {
//                 int diff = tasks[i][0] - maxi;
//                 maxi = oldMaxi + diff;
//                 oldMaxi = maxi;
//                 maxi = maxi - tempSum;
//                 i=i-1;
//             }
//         }
//         return 0;
//     }
// };


class Solution {
public:
    bool isPossible(vector<vector<int>> &tasks,vector<pair<int,int>> v,int mid){
        for(int i=0;i<v.size();i++){
            int idx = v[i].second;
            if(tasks[idx][1] <= mid){
                mid-=tasks[idx][0];
            }
            else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int low = 0, high = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][1]-tasks[i][0],i});
            low += tasks[i][0];
            high += tasks[i][1];
        }

        sort(v.rbegin(),v.rend());
        int ans = INT_MAX;

        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(tasks,v,mid)){
                high = mid-1;
                ans = min(ans,mid);
            }
            else low = mid+1;
        }
        return ans;

    }
};




















