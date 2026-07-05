class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int i=0,j=0,k=0;
        while(k!=s.length()) s[k++]=='a' ? i++ : j++;
        return abs(i-j);
    }
};