class Solution {
public:
    string ans = "";
    void solve(string num1, string num2,int &carry){
        if(num1.length()==0 && num2.length()==0) return;
        int d1 = 0;
        int d2 = 0;

        if(num1.length()>0) d1 = num1[num1.length()-1] - '0';
        if(num2.length()>0) d2 = num2[num2.length()-1] - '0';

        int sum = (d1+d2+carry)%10;
        carry = (d1 + d2 + carry) / 10;
        ans.push_back(sum+'0');
        if(num1.length()>0) num1.pop_back();   
        if(num2.length()>0) num2.pop_back();   
        solve(num1,num2,carry);
    }
    string addStrings(string num1, string num2) {
        int carry = 0;
        solve(num1,num2,carry);
        if(carry!=0) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};