class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string temp = s + s;

        for(int i=0;i<temp.size()-goal.size();i++){
            if(temp.substr(i,goal.size()) == goal ){//Har position se goal.size() length ka substring check
                return true;
            }
        }
        return false;
    }
};