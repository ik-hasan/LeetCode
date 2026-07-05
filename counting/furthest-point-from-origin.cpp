class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r=0,l=0,u=0;
        for(auto it:moves){
            if(it=='L') l++;
            else if(it=='R') r++;
            else u++;
        }
        if(l>r) return l+u-r;
        else return r+u-l;
    }
};