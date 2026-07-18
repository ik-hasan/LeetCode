class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.size()==0) {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
                continue;
            }
            
            bool flag = true;
            while(st.top()<nums2[i]){
                st.pop();
                if(st.empty()){
                    mp[nums2[i]] = -1;
                    st.push(nums2[i]);
                    flag = false;
                    break;
                }
            }
            if(flag){
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }

        for(auto it: nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};