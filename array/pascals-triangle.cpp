class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;

        for(int i=2;i<n;i++){
            auto temp = ans[i-1];
            vector<int> temp2;
            temp2.push_back(1);
            for(int j=1;j<i;j++){
                temp2.push_back(temp[j-1]+temp[j]);
            }
            temp2.push_back(1);
            ans.push_back(temp2);
        }
        return ans;
        
    }
};

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ret;
//         for (int i = 0; i < numRows; i++) {
//             vector<int> row(i + 1, 1);
//             for (int j = 1; j < i; j++) {
//                 row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
//             }
//             ret.push_back(row);
//         }
//         return ret;
//     }
// };
