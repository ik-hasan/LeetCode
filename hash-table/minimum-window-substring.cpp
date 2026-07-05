// class Solution {
// public:
//     string minWindow(string s, string t) {
//         //variable size window question

//         int n = s.length();
//         int m = t.length();
//         if(m>n) return "";

//         int st = 0;
//         int end = 0;

//         int ans = INT_MAX;
//         string res = "";

//         unordered_map<char,int> freq;
//         for(auto it : t){
//             freq[it]++;
//         }
//         while(end < s.length()){

//             //target ki length bdi h window se
//             if(end-st+1 < m){
//                 end++;
//                 continue;
//             }
//             else{
//                 // yha pr agr hm chahe ki ek substring bnale
//                 //s.substr(end-st+1) krke fir target string wale saare char isme aa gye to 
//                 //ye ek answer bn jaega, but question me "including duplicates" bola h isliye
//                 //sirf substring nikal kr solve krna glt hoga.

//                 unordered_map<char,int> temp = freq;
//                 string s1 = s.substr(st, end - st + 1);
//                 for(auto it:s1){
//                     temp[it]--;
//                 }
//                 bool flag = true;
//                 for(auto it:temp){
//                     if(it.second >0){
//                         flag = false;//mtlb ki s1 me t ke saare char nhi h.
//                     }
//                 }
//                 if(flag){
//                     int x = ans;
//                     ans = min(ans,end-st+1);
//                     if(x!=ans) {
//                         res = s.substr(st,end-st+1);
//                     }
//                 }

//                 //shrinking
//                 while(flag){
//                     st++;
//                     unordered_map<char,int> temp2 = freq;
//                     string s2 = s.substr(st, end - st + 1);
//                     for(auto it:s2){
//                         temp2[it]--;
//                     }
//                     for(auto it:temp2){
//                         if(it.second >0){
//                             flag = false;//mtlb ki s2 me t ke saare char nhi h.
//                         }
//                     }
//                     if(flag){
//                         int x = ans;
//                         ans = min(ans,end-st+1);
//                         if(x!=ans) {
//                             res = s.substr(st,end-st+1);
//                         }
//                     }
//                 }
//             }
//             end++;
//         }
//         return res;
//     }
// };













// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int len1 = s.length();
//         int len2 = t.length();

//         if(len1 < len2) {
//             //no answer
//             return "";
//         }

//         //inn do variables k basis opr main exact string find out kr skta hu , substr use krke
//         int ansIndex = -1;
//         int ansLen = INT_MAX;

//         //below 2 maps reflect the current windows of the string s
//         unordered_map<char,int> sMap;
//         unordered_map<char, int> tMap;

//         //values fill krte h tMap k andar 
//         for(auto i: t) {
//             tMap[i]++;
//         }

//         int start = 0;
//         int end = 0;
//         //count tracks total matched characters in the window
//         int count = 0;

//         //variable-size window wlaa logic run krte h 
//         while(end < s.length()) {
//             char ch = s[end];
//             //udpate krna h sMap me, kyoki sMap  "s" wali string 
//             //ki window me kon kon se characters h unko track krne k liye banaya h 
//             sMap[ch]++;
//             //possibility h ye character t k andar ho ya fer na ho
//             //agar ye character t wali string me bhi h , 
//             //toh isko matched characters k andar count krna padega 
//             if(sMap[ch] <= tMap[ch]) {
//                 count++;
//             }

//             //ab ye bhi ho skta h k count i.e. total number of matched characters exactly
//             // len2 i.e. length of string t kequal aajaye 
//             //iska mtlb ek aisi window milgyi h jisme t k saare character presnet h 
//             if(count == len2) {
//                 //mujhe 1 aise window milgyi h, jisme answer present  h
//                 //ab hm shrink krenge
//                 while(sMap[s[start]] > tMap[s[start]]) {
//                     sMap[s[start]]--;
//                     start++;
//                 }
//                 //ans store 
//                 int windowKiLength = end - start + 1;
//                 if(windowKiLength < ansLen) {
//                     ansLen = windowKiLength;
//                     ansIndex = start;
//                 }
//             }
//             //ab line 60 pr kab aaoge ?
//             //jab ek valid ans nhi milta, tab hum expand krte h 
//             end++;
//         }
//         if(ansIndex == -1) {
//             return "";
//         }
//         else {
//             return s.substr(ansIndex, ansLen);
//         }
//     }
// };













// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.length();
//         int m = t.length();

//         if(m>n) return "";

//         unordered_map<char,int> tMap;
//         unordered_map<char,int> sMap;

//         for(auto &it: t){
//             tMap[it]++;
//         }

//         int ansIndex = -1;
//         int ansLen = INT_MAX;
//         int count = 0;

//         int st = 0,end=0;

//         string ans = "";

//         while(end < n){
//             char ch = s[end];
//             sMap[ch]++;
//             if(sMap[ch] <= tMap[ch]){
//                 count++;
//             }

//             if(count==m){
//                 while(sMap[s[st]] > tMap[s[st]]){
//                     sMap[s[st]]--;
//                     st++;
//                 }
//                 int windowLength = end-st+1;
//                 if(ansLen > windowLength){
//                     ansLen = windowLength;
//                     ansIndex = st;
//                 }

                
//             }
//             end++;
//         }

//         if(ansIndex == -1) return "";
//         return s.substr(ansIndex,ansLen);
//     }
// };


















class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:t){
            mp[it]++;
        }

        int l=0,r=0,cnt=0,ans=INT_MAX,stIndex=-1;

        while(r<s.length()){
            mp[s[r]]--;
            if(mp[s[r]]>=0) cnt++;
            while(cnt == t.length()){
                // if(cnt==t.length()) {
                    // ans = min(ans,r-l+1);
                    // if(r - l + 1 <= ans) stIndex=l;
                // }
                if(r - l + 1 < ans){
                    ans = r - l + 1;
                    stIndex = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] >0 ) cnt--;
                l++;
            }
            r++;
        }
        if(stIndex==-1) return "";
        return s.substr(stIndex,ans);
    }
};





























