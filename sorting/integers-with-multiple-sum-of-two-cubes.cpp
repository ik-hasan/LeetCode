class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        int end = cbrt(n);
        unordered_map<int,int> freq;
        for(int i =0;i<=end;i++){
            for(int j = i;j<=end;j++){
                long long val = 1LL*i*i*i + 1LL*j*j*j;

                if(val > n) break;
                freq[val]++;
            }
            
        }
        vector<int> ans;
        for(auto &it:freq){
            if(it.second>=2) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};