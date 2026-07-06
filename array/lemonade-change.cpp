class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(auto it:bills) mp[it]++;

        int five = mp[5];
        int ten = mp[10];
        int twenty = mp[20];

        bool ans = false;
        if(five>=ten) {
            five-=ten;
        }
        else return false;

        if((twenty<=ten && twenty<=five) || twenty<=3*five) ans = true;
        return ans;
    }
};