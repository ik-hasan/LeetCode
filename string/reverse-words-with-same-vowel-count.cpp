class Solution {
public:
    string reverseWords(string s) {
        //if string has no space
        int a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') a++;
        }
        if(a==0) return s;

        
        int i=0;
        int noVowels = 0;
        while(s[i]!=' '){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                noVowels++;
            }
            i++;
        }

        for(int j=i+1;j<s.size();j++){
            int b =0;
            int k =j;
            while(s[k]!=' ' && k<s.size()){
                if(s[k]=='a' || s[k]=='e' || s[k]=='i' || s[k]=='o' || s[k]=='u'){
                    b++;
                }
                k++;
            }
            if(noVowels==b){
                reverse(s.begin()+j,s.begin()+k);
            }
            j=k;
        }
        return s;
    }
};