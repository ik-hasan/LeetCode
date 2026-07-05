class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs.back();

        int i = 0, n = min(a.size(), b.size());

        //Jo strings lexicographically sabse zyada different hoti hain, wo sorted list me ekdum first aur ekdum last position par aa jaati hain.
        while (i < n && a[i] == b[i]) i++;

        return a.substr(0, i);
    }
};