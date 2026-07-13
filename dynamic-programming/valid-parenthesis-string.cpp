class Solution {
public:
    bool checkValidString(string s) {
        int open=0,star=0,close=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='(') open++;
        //     else if(s[i]==')') close++;
        //     else star++;
        // }
        // cout<<open<<" "<<close<<" "<<star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else if(s[i]==')') open--;
            else star++;
        }
        if(open==0) return true;
        if(abs(open)<=star) return true;
        return false;
    }
};