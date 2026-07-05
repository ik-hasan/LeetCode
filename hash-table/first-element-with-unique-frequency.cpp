class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto x:nums){
            mp[x]++;
        }

        unordered_map<int,int> freqCount;
        for(auto &x:mp){
            freqCount[x.second]++;
        }

        for(auto x:nums){
            if(freqCount[mp[x]]==1){
                return x;
            }
        }
        return -1;
    }
};