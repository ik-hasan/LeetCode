class Solution {
public:
    int longestBalanced(string s) {

        int n = s.length();
        int ans = INT_MIN;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq.clear();
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int cnt = freq[s[j]];
                bool flag = true;
                for(auto it: freq){
                    if(it.second != cnt) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};