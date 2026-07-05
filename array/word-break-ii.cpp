class Solution {
public:
    bool compare(string s, vector<string>& wordDict){
        for(int i = 0; i < wordDict.size(); i++){
            if(s == wordDict[i]) return true;
        }
        return false;
    }

    void solveRec(string &s, vector<string>& wordDict, int i, int j, string path, vector<string>& ans){
        // poori string consume ho gayi
        if(j >= s.size() && i<s.size()) return;
        if(j == s.size() && i == s.size()){
            path.pop_back();          // last space hatao
            ans.push_back(path);
            return;
        }

        // j end tak chala gaya but i abhi baaki

        // current substring valid word hai
        if(compare(s.substr(i, j - i + 1), wordDict)){
            string word = s.substr(i, j - i + 1);
            solveRec(s, wordDict, j + 1, j + 1, path + word + " ", ans);
        }

        solveRec(s, wordDict, i, j + 1, path, ans);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        solveRec(s, wordDict, 0, 0, "", ans);
        return ans;
    }
};
