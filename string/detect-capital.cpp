class Solution {
public:
    bool detectCapitalUse(string w) {
        if(w.size()==1) return true;

        //should be all small
        if(w[0]<'A' || w[0]>'Z') {
            for(int i=1;i<w.size();i++){
                if(w[i]>='A' && w[i]<='Z') return false;
            }
        }

        //should be all capital
        if(w[0]>='A' && w[0]<='Z' && w[1]>='A' && w[1]<='Z'){
            for(int i=2;i<w.size();i++){
                if(w[i]<'A' || w[i]>'Z') return false;
            }
            return true;
        }

        //first should be capital then all small
        if(w[0]>='A' && w[0]<='Z'){
            for(int i=1;i<w.size();i++){
                if(w[i]>='A' && w[i]<='Z') return false;
            }
        }
        return true;
    }
};