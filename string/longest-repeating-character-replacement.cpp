// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int l=0,r=0,ans=INT_MIN;

//         for(char ch='A';ch<='Z';ch++){
//             int diff = 0;
//             l=0,r=0;
//             for(auto it:s){
//                 if(it!=ch) diff++;
//                 while(diff>k){
//                     if(s[l]!=ch) diff--;
//                     l++;
//                 }
//                 ans = max(ans,r-l+1);
//                 r++;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int l=0,r=0,ans=INT_MIN,maxFreq=0;
//         vector<int> freq(26,0);
//         while(r<s.length()){
//             freq[s[r]-'A']++;
//             maxFreq = max(maxFreq, freq[s[r]-'A']);
//             while((r-l+1) - maxFreq > k){
//                 freq[s[l]-'A']--;
//                 for(auto it:freq){
//                     maxFreq = max(maxFreq,it);
//                 }
//                 l++;
//             }
//             ans = max(ans,r-l+1);
//             r++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,ans=INT_MIN,maxFreq=0;
        vector<int> freq(26,0);
        while(r<s.length()){
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);
            if((r-l+1) - maxFreq > k){
                freq[s[l]-'A']--;
                maxFreq=0;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};