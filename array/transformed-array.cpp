class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int a = nums[i];
            if(a==0) {
                result[i]=nums[i];
            }
            else if(a>0){
                int x=i;
                for(int j=1;j<=a;j++){
                    if(x==n-1) x=0;
                    else x++;
                }
                result[i]=nums[x];
            }
            else{
                int x=i;
                for(int j=1;j<=-a;j++){
                    if(x==0) x=n-1;
                    else x--;
                }
                result[i]=nums[x];
            }
        }
        return result;
    }
};