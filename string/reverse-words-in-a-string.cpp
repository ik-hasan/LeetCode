class Solution {
public:

    string trim(string s) {

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            ans += s[i];

            if (s[i] == ' ') {
                while (i + 1 < s.size() && s[i + 1] == ' ') {
                    i++;
                }
            }
        }

        return ans;
    }

    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        string ss = trim(s);

        int i = 0;
        int n = ss.size() - 1;

        while (i <= n && ss[i] == ' ')
            i++;

        while (n >= i && ss[n] == ' ')
            n--;

        string newS = ss.substr(i, n - i + 1);

        int st = 0;

        for (int i = 0; i <= newS.size(); i++) {

            if (i == newS.size() || newS[i] == ' ') {

                reverse(newS.begin() + st, newS.begin() + i);

                st = i + 1;
            }
        }

        return newS;
    }
};