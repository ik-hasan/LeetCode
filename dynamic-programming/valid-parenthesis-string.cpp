class Solution {
public:
    bool solve(int open, int i, string &s){
        if(open < 0) return false;

        if(i == s.size()) return open == 0;

        bool a=false,b=false,c=false;
        if(s[i]=='(') a = solve(open+1,i+1,s);
        else if(s[i]==')') b = solve(open-1, i+1,s);
        else{
            c = solve(open+1,i+1,s) || //'('
            solve(open-1,i+1,s) || //')'
            solve(open,i+1,s); //empty string
        }
        return a || b || c;
    }
    bool checkValidString(string s) {
        int open = 0;
        return solve(open,0,s);
    }
};
