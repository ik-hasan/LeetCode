class Solution {
public:

    int sum (vector<int> temp,int n){
        int summ = 0;
        for(auto it:temp){
            summ+=it;
        }
        return summ;
    }
    void solve(int k,int n,set<vector<int>> &st,vector<int> temp,int i){
        if(temp.size()==k){
            if(sum(temp,n)==n) st.insert(temp);
            return;
        }

        if(i>9) return;

        temp.push_back(i);
        solve(k,n,st,temp,i+1);
        temp.pop_back();
        solve(k,n,st,temp,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> st;
        vector<int> temp;
        solve(k,n,st,temp,1);

        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(*st.begin());
            st.erase(*st.begin());
        }

        return ans;
    }
};