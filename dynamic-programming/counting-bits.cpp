class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int n = i;
            long long count = 0;
            while(n>0){
                n = n & (n-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};