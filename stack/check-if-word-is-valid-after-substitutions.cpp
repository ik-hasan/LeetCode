class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() && (s[i]=='c' || s[i]=='b')) return false;
            else if(!st.empty() && s[i]=='c' && st.top()!='b') return false;
            else if(!st.empty() && s[i]=='b' && st.top()!='a') return false;

            else if(s[i]=='a' || s[i]=='b') {
                st.push(s[i]);
            }
            else {
                st.pop();st.pop();
            }
        }
        return st.empty();
    }
};