class Solution {
public:

    bool isPalindrome(string &s, int i, int j){
        if(i>=j) return true;
        if(s[i]!=s[j]){
            return false;
        }
        return isPalindrome(s,i+1,j-1);;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s,i,j)){
                    string t = s.substr(i,j-i+1);
                    if(t.size()>ans.size()) ans = t;
                }
            }
        }
        return ans;
    }
};