// class Solution {
// public:
//     bool equal(int st,int end,vector<int> &nums){
//         int odd=0,even=0;
//         unordered_map<int,bool> visited;
//         for(int i=st;i<=end;i++){
//             if(nums[i]%2==0 && !visited[nums[i]]) even++;
//             else if(nums[i]%2!=0 && !visited[nums[i]])odd++;
//             visited[nums[i]]=true;
//         }
//         return odd==even;
//     }
//     int longestBalanced(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             for(int j=n-1;j>=i;j--){
//                 if(j - i + 1 <= ans) break;   // pruning
//                 else if(equal(i,j,nums)){
//                     ans = j - i + 1;
//                     break;  // max for this i found
//                 }
//             }
//             if(ans == n) break;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> odd, even;
            for (int j = i; j < n; j++) {
                if (nums[j] %2 != 0)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);

                if (odd.size() == even.size())
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};