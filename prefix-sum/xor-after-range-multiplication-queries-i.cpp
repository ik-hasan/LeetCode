typedef long long ll;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries ) {
        int mod = 1e9+7;
        for(auto q:queries ){
            int i=q[0];
            while(i<=q[1] && i<nums.size()){
                long long x = ((ll)nums[i]*(ll)q[3]) % (ll)mod;
                nums[i] = (int)x;
                i += q[2];
            
            }
        }

        int temp = nums[0];
        for(auto i=1;i<nums.size();i++){
            temp ^= nums[i];
        }
        return temp;
    }
};