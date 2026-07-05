class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        if(k==0) return nums.size();

        sort(nums.begin(),nums.end());
        
        int e=nums.size()-1;
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1] && nums[nums.size()-k]==nums[i] ){
                continue;
            }
            else if(e-i >= k) ans++;
        }
        return ans;
    }
};



// class Solution {
// public:
//     int countElements(vector<int>& nums, int k) {

//         sort(nums.begin(),nums.end());
//         int ans=0;

//         for(int i=0;i<nums.size();i++){
//             int count=0;
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]<nums[j]){
//                     count++;
//                     if(count >= k) break;
//                 }
//             }
//             if(count >= k) ans++;
//         }
//         return ans;
        
//     }
// };