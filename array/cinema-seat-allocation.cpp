class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        map<int, set<int>> mp;
        
        for(auto x : reservedSeats) {
            mp[x[0]].insert(x[1]);
        }
        
        int ans = (n - mp.size()) * 2;
        
        for(auto it : mp) {
            int row = it.first;
            set<int> s = it.second;
            
            bool left = true;
            bool mid = true;
            bool right = true;
            
            // seats 2,3,4,5
            for(int i = 2; i <= 5; i++) {
                if(s.count(i)) {
                    left = false;
                    break;
                }
            }
            
            // seats 4,5,6,7
            for(int i = 4; i <= 7; i++) {
                if(s.count(i)) {
                    mid = false;
                    break;
                }
            }
            
            // seats 6,7,8,9
            for(int i = 6; i <= 9; i++) {
                if(s.count(i)) {
                    right = false;
                    break;
                }
            }
            
            if(left && right)
                ans += 2;
            else if(left || mid || right)
                ans += 1;
        }
        
        return ans;
    }
};