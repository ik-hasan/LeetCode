class Solution {
public:

    void solve(vector<int> &v, int target,vector<vector<int>> &ans,vector<int> temp,int index){

        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<v.size();i++){
            //saara kam is line se ho rha h, 
            //agr i index se bda chal rha h & v[i]==v[i-1] to ye
            //duplicate formation ho rha h yha pr isliye conntinue kr denge
            if(i > index && v[i]==v[i-1]) continue;
            if(v[i] > target) continue;
            temp.push_back(v[i]);
            solve(v,target-v[i],ans,temp,i+1);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,ans,temp,0);
        
        return ans;
    }
};