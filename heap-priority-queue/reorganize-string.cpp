// class Solution {
// public:
//     string reorganizeString(string s) {
//         sort(s.begin(),s.end());
//         string a = "";
//         int st=0,end=s.length()-1;
//         while(st<=end){
//             if(st==end) {
//                 a.push_back(s[st++]);
//                 continue;
//             }
//             a.push_back(s[st++]);
//             a.push_back(s[end--]);
//         }
//         for(int i=1;i<a.length();i++){
//             if(a[i-1]==a[i]) return "";
//         }
//         return a;
//     }
// };


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto &ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int,char>> maxHeap;
        for(auto &[ch,freq] : mp){
            maxHeap.push({freq,ch});
        }

        string res = "";
        while(maxHeap.size()>=2){
            auto [freq1,ch1] = maxHeap.top();maxHeap.pop();
            auto [freq2,ch2] = maxHeap.top();maxHeap.pop();

            res+=ch1;
            res+=ch2;

            if(freq1-1 > 0) maxHeap.push({freq1-1,ch1});
            if(freq2-1 > 0) maxHeap.push({freq2-1,ch2});
        }

        if(maxHeap.size()!=0){
            auto [freq1,ch1] = maxHeap.top();
            if(freq1-1 != 0) return "";
            res+=ch1;
        }
        return res;
    }
};
