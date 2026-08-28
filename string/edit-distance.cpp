class Solution {
public:

    int solve(int i, int j, string &s1, string &s2){
        if(j>=s2.length()) return s1.length()-i;
        if(i>=s1.length() && j<s2.length()) return s2.length()-j;
        if(i>=s1.length()) return 0;

        if(s1[i]==s2[j]) return solve(i+1,j+1,s1,s2);

        return 1 + min(solve(i+1,j,s1,s2),solve(i+1,j+1,s1,s2));
    }
    int minDistance(string word1, string word2) {
        return solve(0,0,word1,word2);
    }
};