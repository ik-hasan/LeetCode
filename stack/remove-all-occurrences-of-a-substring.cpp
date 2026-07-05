class Solution {
public:
    void solve(string &s, string part){
        if(part.length() > s.length()) return;

        int ssz = s.size();
        int psz = part.size();

        for(int i=0;i<=ssz-psz;i++){
            if(s.substr(i,psz)==part){
                s.erase(i,psz);
                solve(s,part);
                return;
            }
        }
    }
    string removeOccurrences(string s, string part) {
        solve(s,part);
        return s;
    }
};