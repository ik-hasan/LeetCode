class Solution {
public:
    int maxDepth(string s) {
        int ans = 0,depth = 0;
        for(auto it:s){
            if(it=='('){
                depth++;
                ans = max(ans,depth);
            }
            else if(it==')') depth--;
        }
        return ans;
    }
};