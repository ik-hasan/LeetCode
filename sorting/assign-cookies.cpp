class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=g.size()-1,j=s.size()-1;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                i--;
                j--;
                ans++;
                continue;
            }
            else if(s[j]<g[i]){
                i--;
                continue;
            }
        }
        return ans;
    }
};