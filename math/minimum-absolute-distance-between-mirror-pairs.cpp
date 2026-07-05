

// class Solution {
// public:
//     int minMirrorPairDistance(vector<int>& nums) {
//         int minDist = INT_MAX;
//         unordered_map<int,int> mp;

//         for(int i=0;i<nums.size();i++){
//             string s = to_string(nums[i]);
//             reverse(s.begin(),s.end());
//             int newElem = stoi(s);
            
//             if(mp.count(newElem)){
//                 minDist = min(abs(i-mp[newElem]),minDist);
//             }
//             mp[nums[i]]=i;
//         }
//         if(minDist==INT_MAX) return -1;
//         return minDist;
//     }
// };

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int minDist = INT_MAX;
        unordered_map<int, int> mp; 
        
        for(int i = 0; i < nums.size(); i++){
            
            if(mp.count(nums[i])){
                minDist = min(minDist, i - mp[nums[i]]);
            }
            
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int reversed = stoi(s);
            
            mp[reversed] = i;
        }
        
        return (minDist == INT_MAX) ? -1 : minDist;
    }
};

//tle
// class Solution {
// public:
//     int minMirrorPairDistance(vector<int>& nums) {
//         int minDist = INT_MAX;

//         for(int i=0;i<nums.size();i++){
//             int temp = nums[i];
//             string s = to_string(temp);
//             reverse(s.begin(),s.end());
//             int newElem = stoi(s);
//             auto x = find(nums.begin()+i+1,nums.end(),newElem);
//             if(x!=nums.end()){
//                 //mtlb ki mil gya elem
//                 int index = x - nums.begin();
//                 minDist = min(index-i,minDist);
//             }
//         }
//         if(minDist==INT_MAX) return -1;
//         return minDist;
//     }
// };

//tle
// class Solution {
// public:
//     int minMirrorPairDistance(vector<int>& nums) {
//         int minDist = INT_MAX;

//         for(int i=0;i<nums.size();i++){
//             int temp = nums[i];
//             string s = to_string(temp);
//             reverse(s.begin(),s.end());
//             int newElem = stoi(s);

//             for(int j = i + 1; j < nums.size(); j++){   
//                 if(nums[j] == newElem){
//                     minDist = min(minDist, j - i); 
//                 }
//             }
//         }
//         if(minDist==INT_MAX) return -1;
//         return minDist;
//     }
// };