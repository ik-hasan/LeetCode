// class Solution {
// public:
//     bool hasAlternatingBits(int n) {
//         string s="";
//         while(n!=0){
//             s+= (n%2)+'0';
//             n=n/2;
//         }

//         for(int i=1;i<s.length();i++){
//             if(s[i-1]==s[i]) return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n&1;
        n=n>>1;

        while(n>0){
            int curr = n&1;
            if(curr == prev){
                return false;
            }
            prev = curr;
            n=n>>1;
        }
        return true;
    }
};