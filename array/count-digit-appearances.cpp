class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(auto it:nums){
            if(it==0 && digit==0){
                ans++;
                continue;
            }
            while(it){
                int x=it%10;
                it=it/10;
                if(x==digit) ans++;
            }
        }
        return ans;
    }
};