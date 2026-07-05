class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // int a = INT_MIN;
        // int b = INT_MAX;
        // for(auto it : nums1){
        //     a = max(a,it);
        //     b = min(b,it);
        // }
        // if(a-b==1) return false;
        // return true;
        
        int a = INT_MAX;
        for(auto it : nums1){
            a = min(a,it);
        }
        if(a%2==0){
            for(auto it:nums1){
                if(it%2==1) return false;
            }
        }
        return true;
    }
};