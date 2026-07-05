class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(haystack.size()==1 && needle.size()==1 && ){
        //     return 0;
        // }
        if(needle.empty()) return 0;
        int j=1;
        bool flag= false;
        for(int i=0;i<haystack.size();i++){
            bool flag= true;
            if(haystack[i]==needle[0]){
                for(int j=1;j<needle.size();j++){
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag==true){
                    return i;
                }
            }
        }
        return -1;
    }
};