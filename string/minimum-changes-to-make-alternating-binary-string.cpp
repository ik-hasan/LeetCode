class Solution {
public:
    int minOperations(string s) {
        int pat1 = 0;//for 01010101... pattern
        int pat2 = 0;//for 10101010... pattern

        for(auto &it:s){
            if(it == '0') pat1++;
            else pat2++;
            swap(pat1,pat2);
        }
        return min(pat1,pat2);
    }
};