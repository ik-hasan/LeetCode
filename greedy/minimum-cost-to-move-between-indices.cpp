class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int> forward(n,0);

        for(int i=0;i<n-1;i++){
            int leftDiff = (i>0) ? nums[i]-nums[i-1] : INT_MAX;
            int rightDiff = nums[i+1] - nums[i];

            if(leftDiff > rightDiff){
                forward[i+1] = forward[i]+1;
            }
            else {
                forward[i+1] = forward[i] + rightDiff;
            }
        }

        vector<int> backward(n,0);
        for(int i=n-1;i>0;i--){
            int leftDiff = nums[i]-nums[i-1] ;
            int rightDiff = (i<n-1) ? nums[i+1]-nums[i] : INT_MAX;

            if(leftDiff <= rightDiff){
                backward[i-1] = backward[i]+1;
            }
            else {
                backward[i-1] = backward[i] + leftDiff;
            }
        }

        vector<int> ans;
        for(auto q:queries){
            int left = q[0];
            int right = q[1];
            if(left<=right) ans.push_back(forward[right] - forward[left]);
            else ans.push_back(backward[right] - backward[left]);
        }
        return ans;
    }
};