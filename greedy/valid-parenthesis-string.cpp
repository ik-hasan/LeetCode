class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        for(int i=0;i<s.size();i++){
            if(open<0) return false;
            if(s[i]=='(') open++;
            else if(s[i]==')') open--;
        }
        if(open>0) return false;
        return true;
    }
};