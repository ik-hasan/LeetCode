class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto a:s){
            if(a=='(' || a=='{' || a=='[') st.push(a);
            else{
                if( st.size()==0 ) return false; // iska mtlb h ki phla bracket hi closing wala h
                else if( st.top()=='(' && a==')' ) st.pop();
                else if( st.top()=='{' && a=='}' ) st.pop();
                else if( st.top()=='[' && a==']' ) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};