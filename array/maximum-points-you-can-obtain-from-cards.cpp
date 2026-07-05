class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int sum = accumulate(c.begin(),c.begin()+k,0);
        int l=k-1,r=c.size()-1;
        int ans = INT_MIN;
        while(l>=0){
            ans = max(ans,sum);
            sum = sum - c[l--] + c[r--];
        }
        return max(ans,sum);
    }
};