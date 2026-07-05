//TLE
// class Solution {
// public:
//     int minFlips(string s) {
//         int pat1 = 0;//01010101...
//         int pat2 = 0;//10101010...

//         int ans = INT_MAX;
//         for(int i=0;i<s.size();i++){

//             for(auto &it:s){
//                 if(it=='0') pat1++;
//                 else pat2++;
//                 swap(pat1,pat2);
//             }

//             ans = min(ans,min(pat1,pat2));

//             char ch = s[0];
//             s.erase(0,1);
//             s.push_back(ch);
//             pat1=0;
//             pat2=0;
//         }
//         return ans;
//     }
// };



//optimized
class Solution {
public:
    int minFlips(string s) {

        string t = s+s;//aisa krne se saare possible rotation isme hi include ho jaenge.
        int n = t.size();

        string patOfStr1 = "";//010101...
        string patOfStr2 = "";//101010...
        for(int i = 0;i<n;i++){
            if(i%2==0){
                patOfStr1+='0';
                patOfStr2+='1';
            }
            else{
                patOfStr1+='1';
                patOfStr2+='0';
            }
        }

        int ans = INT_MAX;
        int left = 0;
        int pat1 = 0;
        int pat2 = 0;
        
        for(int i=0;i<n;i++){
            
            if(t[i]!=patOfStr1[i]) pat1++;
            if(t[i]!=patOfStr2[i]) pat2++;

            //here, we are shifting the window
            if(i-left+1 > s.size()){
                if(t[left]!=patOfStr1[left]) pat1--;
                if(t[left]!=patOfStr2[left]) pat2--;
                left++;
            }

            if(i-left+1 == s.size()) ans = min(ans,min(pat1,pat2));

        }
        return ans;
    }
};
