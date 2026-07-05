class Solution {
public:
    void solve(vector<char>& s,int st, int e){
        if(st>e) return;
        swap(s[st],s[e]);
        solve(s,st+1,e-1);
    }
    void reverseString(vector<char>& s) {
        solve(s,0,s.size()-1);
        // cout<<s.size();
    }
};