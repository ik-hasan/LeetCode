class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int min = INT_MAX;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1]) < min) min=abs(arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1]) == min){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};