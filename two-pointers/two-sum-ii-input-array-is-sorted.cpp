class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int st = 0,e=arr.size()-1;
        vector<int> ans;
        while(st<=e){
            int sum = arr[st]+arr[e];
            if(sum==target){
                ans.push_back(st+1);
                ans.push_back(e+1);
                break;
            }
            else if(sum > target){
                e--;
            }
            else{
                st++;
            }
        }
        return ans;
    }
};