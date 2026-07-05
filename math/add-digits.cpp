class Solution {
public:
    int addDigits(int num) {
        // int s = num/10;
        if(num < 10) return num;
        string s = to_string(num);
        int sum =0;
        for (int i=0;i<s.size();i++){
            int x = s[i]-'0';
            sum=sum+x;
        }
        return addDigits(sum);
    }
};
