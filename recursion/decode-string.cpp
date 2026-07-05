class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char ch : s) {
            if (ch == ']') {
                string stringToRepeat = "";
                while (!st.empty() && st.top() != "[") {
                    stringToRepeat = st.top() + stringToRepeat;
                    st.pop();
                }

                st.pop(); // remove '['

                string numericTimes = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numericTimes = st.top() + numericTimes;
                    st.pop();
                }

                int n = stoi(numericTimes);
                string currentdecode = "";
                while (n--) {
                    currentdecode += stringToRepeat;
                }

                st.push(currentdecode);
            } else {
                st.push(string(1, ch));
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }

};