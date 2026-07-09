// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
//         int i=0;
//         int n = intervals.size();
//         int first = newInterval[0];
//         int sec = newInterval[1];

//         //finding sec position
//         while(i<n){
//             int e = intervals[i][1];
//             if(e>=sec) break;
//             i++;
//         }
//         int k = i;
//         i=0;

//         //finding first position
//         while(i<n){
//             int s = intervals[i][0];
//             int e = intervals[i][1];
//             if(e>=first && s<=first) break;
//             else if(e>=first){
//                 i--;
//                 break;
//             }
//             i++;
//         }
//         int j = i;


//         vector<vector<int>> ans;
//         for(int l=0;l<j;l++){
//             ans.push_back(intervals[l]);
//         }

//         ans.push_back({intervals[j][0], max(first,intervals[j][1])});

//         if(intervals[k][0] > sec) ans[k-1][1] = sec;
//         else ans[k][0] = sec;

//         for(int l=k+1;l<n;l++){
//             ans.push_back(intervals[l]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        if (n == 0) return {newInterval};

        int first = newInterval[0];
        int sec = newInterval[1];

        int j = 0;

        // First overlapping interval
        while (j < n && intervals[j][1] < first) j++;

        int k = j;

        // Last overlapping interval
        while (k < n && intervals[k][0] <= sec) k++;

        vector<vector<int>> ans;

        // Before overlap
        for (int i = 0; i < j; i++)
            ans.push_back(intervals[i]);

        // No overlap
        if (j == k) {
            ans.push_back(newInterval);
        }
        else {
            int start = min(first, intervals[j][0]);
            int end = max(sec, intervals[k - 1][1]);
            ans.push_back({start, end});
        }

        // Remaining intervals
        for (int i = k; i < n; i++)
            ans.push_back(intervals[i]);

        return ans;
    }
};