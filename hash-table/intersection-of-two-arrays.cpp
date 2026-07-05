
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,bool> used;

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j] && used[nums1[i]] != true){
                    ans.push_back(nums1[i]);
                    used[nums1[i]] = true;
                    break;
                }
            }
        }
        return ans;
    }
};