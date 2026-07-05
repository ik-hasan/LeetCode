class Solution {
public:
    int minAllOneMultiple(int k) {

        if(k % 2==0  || k % 5==0) return -1;
        
        string s = "1";
        int rem = 1 % k;
        int ans = s.size();

        while(rem != 0){
            s.push_back('1');
            // x = stoi(s);
            // rem = rem % k;
            rem =(rem*10 +1) % k;
            ans = s.size();
        }
        return ans;
    }
};