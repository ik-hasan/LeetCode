class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> vis;
        for(auto it:nums1) vis[it] = true;
        for(auto it:nums2){
            if(vis[it]) return it;
        }
        return -1;
    }
};