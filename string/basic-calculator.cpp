class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sum = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');   //multi-digit
            }
            else if (c == '+') {
                sum += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                sum += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                //isi order me push krenge taaki jb s[i]==')' ho to phle abhi tk bne sum me sign ka
                //multiply ho fir uske baad previous sum me add ho.
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (c == ')') {
                sum += sign * num;
                num = 0;
                sum *= st.top(); st.pop();   // previous sign
                sum += st.top(); st.pop();   // previous sum
            }
        }

        sum += sign * num;
        return sum;
    }
};
