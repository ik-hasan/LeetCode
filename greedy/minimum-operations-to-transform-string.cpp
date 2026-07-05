class Solution {
public:
    int minOperations(string s) {
        if(s.length()==1 && s[0]=='a') return 0;
        char ch = s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]=='a') continue;
            if(ch=='a') ch=s[i];
            ch = min(ch,s[i]);
        }
        int ans = 0;
        if(ch=='a') return 0;
        while(ch!='z'){
            ch++;
            ans++;
        }
        return ans+1;
    }
};