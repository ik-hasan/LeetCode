class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){

        //     int s2 = n-i;
        //     int score = s2/2;
        //     ans.push_back(score);
        // }
        
        int n = nums.size();
        vector<int>ans;
        int even=0,odd=0;
        for(int i=0;i<n;i++){

            if(nums[i]%2==0) even++;
            else odd++;
        }

        for(int i=0;i<n;i++){
            if(nums[i]%2==0) even--;
            else odd--;

            if(nums[i]%2==0) ans.push_back(odd);
            else ans.push_back(even);
        }
        return ans;
    }
};