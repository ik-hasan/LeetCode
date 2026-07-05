class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0,del=0;
        for(auto &x : s){
            if(x == 'b') b++;
            else if(b>0){
                b--;
                del++;
            }
        }
        return del;
    }
};