class Solution {
public:

    bool isSortable(vector<int> &a, vector<int> &b){
        vector<int> bb=b;
        bb.insert(bb.end(),b.begin(),b.end());//bb=b+b

        for(int i=0;i<a.size();i++){
            bool flag = true;
            for(int j=0;j<a.size();j++){
                if(bb[i+j] != a[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;
        vector<int> divisors;
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());

        for(int i=1;i<=n/2;i++){
            if(n%i==0) divisors.push_back(i);
        }
        divisors.push_back(n);

        for(auto &k:divisors){
            bool flag = true;
            for(int i=0;i<n;i+=k){
                vector<int> a(nums.begin()+i,nums.begin()+i+k);
                vector<int> b(sorted.begin()+i,sorted.begin()+i+k);
                if(!isSortable(a,b)) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += k; 
        }
        return ans;

        // for(int i=0;i<n/2;i++){
        //     if(n%i == 0){
        //         for(int j=0;j<=n-i;j++){
        //             vector<int> temp(nums.begin(),nums.begin()+k);
        //             for(int k=0;k<i;k++){
        //                 if(is_sorted(temp.begin(),temp.begin()+i)) {
        //                     ans += i;
        //                 }
        //                 else{
                            
        //                 }
        //             }
        //         }
        //     }
        // }
        //n ke liye ek bar aur chlaenge
    }
};