class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.size();
        int st=0,e=n-1;

        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
        while(e>st){
            if (!isalnum(s[st])) {
                st++;
                continue;
            }
            if (!isalnum(s[e])) {
                e--;
                continue;
            }
            if(s[st]!=s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};