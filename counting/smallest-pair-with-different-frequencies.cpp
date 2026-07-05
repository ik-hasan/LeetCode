class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> ans={-1,-1};
        if(nums.size()==1 || nums.size()==2) return ans;
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }

        for(int i=0;i<v.size();i++){
            ans[0]=v[i].first;
            int freq = v[i].second;

            for(int j=i+1;j<v.size();j++){
                if(ans[0]<v[j].first && freq!=v[j].second){
                    ans[1]=v[j].first;
                    break;
                }

            }
            if(ans[1]!=-1) break;
        }
        if(ans[1]==-1) ans[0]=-1;
        return ans;
        
    }
};