// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(auto i: nums){
//             mp[i]++;
//         }
//         cout<<mp.size()<<" ";

//         int y = -1;
//         for(auto x : mp){
//             if(x.second>=3){
//                 y = x.first;
//                 // break;
//             }
//         }
//         cout<<y<<" ";
//         if(y==-1) return -1;

//         int a=-1,b=-1,c=-1;
//         vector<int> index;
//         int j = 0;
//         for(int i =0;i<nums.size();i++){
//             if(nums[i]==y) {
//                 index.push_back(i);
//                 j=i;
//                 break;
//             }
//         }
//         int k = 0;
//         for(int i = j+1;i<nums.size();i++){
//             if(nums[i]==y) {
//                 index.push_back(i);
//                 k=i;
//                 break;
//             }
//         }
//         for(int i = k+1;i<nums.size();i++){
//             if(nums[i]==y) {
//                 index.push_back(i);
//                 // break;
//             }
//         }
//         cout<<index.size();
//         if(index.size()<3) return -1;
//         int ans = INT_MAX;
//         for(int i =0;i<index.size()-2;i++){
//             ans = min(ans , abs(index[i]-index[i+1])+abs(index[i+1]-index[i+2])+abs(index[i+2]-index[i]) );
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> index;

        for(int i = 0; i < nums.size(); i++) {
            index[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto it : index) {
            auto v = it.second;
            if(v.size() < 3) continue;

            for(int i = 0; i <= v.size() - 3; i++) {
                ans = min(ans , abs(v[i]-v[i+1])+abs(v[i+1]-v[i+2])+abs(v[i+2]-v[i]) );
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};



