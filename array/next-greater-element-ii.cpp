class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v(nums.begin(),nums.end());
        for(auto it:nums) v.push_back(it);
        // for(auto it:v) cout<<it<<" ";

        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=v.size()-1;i>=0;i--){
            if(st.size()==0) {
                mp[i] = -1;
                st.push(v[i]);
                continue;
            }
            
            bool flag = true;
            while(v[i]>=st.top()){
                st.pop();
                if(st.empty()){
                    mp[i] = -1;
                    st.push(v[i]);
                    flag = false;
                    break;
                }
            }
            if(flag){
                mp[i] = st.top();
                st.push(v[i]);
            }
        }

        for(int i=0;i<nums.size();i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};