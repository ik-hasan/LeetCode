class Solution {
public:
    vector<int> prevSmaller(vector<int>&arr){
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
    vector<int> nextSmaller(vector<int>&arr){
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
    long long smallersSum(vector<int>& arr) {
        auto next = nextSmaller(arr);
        auto prev = prevSmaller(arr);

        for(int i=0;i<next.size();i++){
            if (next[i] == -1) next[i] = next.size(); 
        }
        
        long long sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+= 1LL*(next[i]-i)*(i-prev[i])*arr[i];
        }
        return sum;
    }
    vector<int> prevGreater(vector<int>&arr){
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(st.top()!=-1 && arr[i] > arr[st.top()]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreater(vector<int> &arr){
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(st.top()!=-1 && arr[i] >= arr[st.top()]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long greatersSum(vector<int>& arr) {
        auto next = nextGreater(arr);
        auto prev = prevGreater(arr);

        for(int i=0;i<next.size();i++){
            if (next[i] == -1) next[i] = next.size(); 
        }
        
        long long sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+= 1LL*(next[i]-i)*(i-prev[i])*arr[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long a = smallersSum(nums);
        long long b = greatersSum(nums);

        return b-a;
    }
};