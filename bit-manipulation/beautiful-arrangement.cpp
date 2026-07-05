class Solution {
public:

    // void solve(vector<int> nums,int &ans,int currElem){
    //     if(currElem>=nums.size()){
    //         ans++;
    //         return;
    //     }

    //     for(int i=1;i<nums.size();i++){
    //         if(nums[i]==0 && (currElem % i==0 || i % currElem==0)){
    //             nums[i]=currElem;
    //             solve(nums,ans,currElem+1);
    //             nums[i]=0;
    //         }
    //     }
    //     return ;
    // }
    // int countArrangement(int n) {
    //     vector<int> nums(n+1,0);
    //     int ans = 0;
    //     solve(nums,ans,1);
    //     return ans;
    // }



    void solve(vector <int> v, int index, int &ans){
        if(index==v.size()){
            ans++;
            return;
        }
        for(int i=index;i<v.size();i++){
            if(v[i]%(index)==0 || (index)%v[i]==0){
                swap(v[i], v[index]);
                solve(v, index+1, ans);
                swap(v[i], v[index]);
            }
        }
    }
        
    int countArrangement(int n) {
        vector <int> v;
        int ans=0;
        for(int i=0; i <= n; i++){
            v.push_back(i);
        }
        solve(v, 1, ans);
        return ans;
    }
};