class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> s1;
        
        for(char x : s) {
            s1[x]++;
        }
        for(char x : t) {
            s1[x]--;
            if(s1[x] < 0) return false;
        }
        
        return true;
    }
};