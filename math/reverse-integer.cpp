class Solution {
public:
    int reverse(int x) {

        bool sign = x < 0;
        if(x >= 2147483648 || x <= -2147483648) return 0;

        string s = to_string(abs(x));
        std::reverse(s.begin(), s.end());//ye aise isliye likhna pda kyuki function name bhi reverse h
        
        if(s.length() > 10) return 0;
        if(s.length() == 10){
            if( !sign && s > "2147483647") return 0;//number +ve h & 2^31 - 1 se bda h to return 0
            if( sign && s > "2147483648") return 0; //number -2^31 se chota h to return 0
        }
        int ans = stoi(s);

        if(sign) return -ans;
        return ans;
    }
};