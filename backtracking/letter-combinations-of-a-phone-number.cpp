class Solution {
public:

    void solve(string digits,unordered_map<char,string> &mp, vector<string> &ans,string temp,int index){
        //base case
        if(index>=digits.size() || temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }


        for(int i=0;i<mp[digits[index]].size();i++){
            char digit = digits[index];
            string strOfDigit = mp[digit];
            temp.push_back(strOfDigit[i]);
            solve(digits,mp,ans,temp,index+1);
            temp.pop_back();
        }
        // solve(digits,mp,ans,temp,index+1);
        return;
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";
        solve(digits,mp,ans,temp,0);
        return ans;
    }
};