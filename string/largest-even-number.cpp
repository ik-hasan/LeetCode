class Solution {
public:
    string largestEven(string s) {
        int i = s.length()-1;

        while(i>=0 && ((s[i]- '0') % 2 != 0)){
            i--;
        }
        if(i<0) return "";

        // cout<<s.substr(0,i+1);

        return s.substr(0,i+1);

    }
};