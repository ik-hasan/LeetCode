class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> index;

        for(int i = 0; i < nums.size(); i++) {
            index[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto it : index) {
            auto v = it.second;
            if(v.size() < 3) continue;

            for(int i = 0; i <= v.size() - 3; i++) {
                ans = min(ans , abs(v[i]-v[i+1])+abs(v[i+1]-v[i+2])+abs(v[i+2]-v[i]) );
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};