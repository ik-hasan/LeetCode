class Solution {
public:
    int romanToInt(string s) {

        //BRUTE FORCE SOLN 
        // int n = s.size();
        // if(n==0){
        //     return n;
        // }
        // int sum = 0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='I' && s[i+1]=='V'){
        //         sum=sum+4;
        //         i++;
        //     }
        //     else if(s[i]=='I' && s[i+1]=='X'){
        //         sum=sum+9;
        //         i++;
        //     }
        //     else if(s[i]=='X' && s[i+1]=='L'){
        //         sum=sum+40;
        //         i++;
        //     }
        //     else if(s[i]=='X' && s[i+1]=='C'){
        //         sum=sum+90;
        //         i++;
        //     }
        //     else if(s[i]=='C' && s[i+1]=='D'){
        //         sum=sum+400;
        //         i++;
        //     }
        //     else if(s[i]=='C' && s[i+1]=='M'){
        //         sum=sum+900;
        //         i++;
        //     }
        //     else if(s[i]=='I'){
        //         sum=sum+1;
        //     }
        //     else if(s[i]=='V'){
        //         sum=sum+5;
        //     }
        //     else if(s[i]=='X'){
        //         sum=sum+10;
        //     }
        //     else if(s[i]=='L'){
        //         sum=sum+50;
        //     }
        //     else if(s[i]=='C'){
        //         sum=sum+100;
        //     }
        //     else if(s[i]=='D'){
        //         sum=sum+500;
        //     }
        //     else if(s[i]=='M'){
        //         sum=sum+1000;
        //     }
        //     else{
        //         sum=sum+0;
        //     }
        // }
        // return sum;



        //SOLN-2 
        unordered_map <char,int> val = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(val[s[i]]<val[s[i+1]]){
                sum=sum-val[s[i]];
            }
            else{
                sum= sum+val[s[i]];
            }
        }
        return sum;
    }
};