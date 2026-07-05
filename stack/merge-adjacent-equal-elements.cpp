class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        // for(int i = 0;i<ans.size()-1;i++){
        //     if(ans[i]==ans[i+1]){
        //         ans[i]=ans[i]+ans[i+1];
        //         ans.erase(ans.begin()+i+1);
        //         i=-1;
        //     }
        // }
        int j =0;
        for(int i = 0;i<ans.size();i++){
            ans[j]= ans[i];
            while(j>0 && ans[j]==ans[j-1]){
                ans[j-1] += ans[j];
                j--;
            }
            j++;
        }
        ans.resize(j);
        return ans;

    }
};