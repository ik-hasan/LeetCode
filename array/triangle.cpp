class Solution {
public:

    int solve(int i,int j, vector<vector<int>>& t){
        if(i==t.size()-1 && j<=t[i].size()-1) return t[i][j];
        if(i>=t.size() || j>=t[i].size()) return INT_MAX;

        int first = solve(i+1,j,t);
        int second = solve(i+1,j+1,t);
        if(first != INT_MAX) first += t[i][j]; 
        if(second != INT_MAX) second += t[i][j]; 
        return min(first,second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0,0,triangle);
    }
};