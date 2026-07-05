class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int st = 0;
        int balance = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') balance++;
            else balance--;
            if(balance==0){
                ans+=s.substr(st+1,i-1-st);
                st = i+1;
            }
        }
        return ans;
    }
};