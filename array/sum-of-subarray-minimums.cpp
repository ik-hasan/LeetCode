class Solution {
public:

    //MLE - 67/88
    // int mod = 1000000009;
    // int solve(vector<int> arr){
    //     if(arr.size()==1) return arr[0];
    //     int x = arr[0];
    //     for(int i=1;i<arr.size();i++){
    //         x=min(x,arr[i]);
    //     }
    //     return x;
    // }
    // int sumSubarrayMins(vector<int>& arr) {
    //     vector<vector<int>> v;
    //     for(int i=0;i<arr.size();i++){
    //         vector<int> temp;
    //         for(int j=i;j<arr.size();j++){
    //             temp.push_back(arr[j]);
    //             v.push_back(temp);
    //         }
    //     }
    //     long long sum = 0;
    //     for(int i=0;i<v.size();i++){
    //         sum += solve(v[i]);
    //     }
    //     return sum%mod;
    // }



    //TLE - 87/88
    // int mod = 1000000007;
    // int sumSubarrayMins(vector<int>& arr) {
    //     int n = arr.size();
    //     long long sum = 0;

    //     for (int i = 0; i < n; i++) {
    //         int mn = arr[i];                 
    //         for (int j = i; j < n; j++) {
    //             mn = min(mn, arr[j]);     
    //             sum += mn;
    //         }
    //     }
    //     return sum % mod;
    // }




    //soln-3
    vector<int> prevSmaller(vector<int>arr){
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(st.top()!=-1 && arr[i] < arr[st.top()]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int>arr){
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(st.top()!=-1 && arr[i] <= arr[st.top()]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmaller(arr);
        auto prev = prevSmaller(arr);

        for(int i=0;i<next.size();i++){
            if (next[i] == -1) next[i] = next.size(); 
        }
        
        long long sum = 0;
        for(int i=0;i<arr.size();i++){
            int x = (next[i]-i) % MOD;
            int y = (i-prev[i]) % MOD;
            sum = (sum + ( (x * y) % MOD * (long long)arr[i] ) % MOD) % MOD; // FIX

        }
        return sum % MOD;
    }

 
};