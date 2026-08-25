class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int i = 1;
        while(true){
            if(find(nums.begin(),nums.end(),i*k)==nums.end()){
                return i*k;
            }
            i++;
        }
        return 0;
    }
};