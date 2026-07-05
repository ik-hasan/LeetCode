class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,bool> vis;

        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        
        int ans = 0;

        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(vis[c]) continue;
            char m;
            if(c>='0' && c<='9') m = '9'-(c-'0');
            else m = 'z'-(c-'a');
            int f1 = freq[c];
            int f2 = freq[m];

            ans += abs(f1-f2);
            vis[c]=true;
            vis[m]=true;
        }
        return ans;
    }
};