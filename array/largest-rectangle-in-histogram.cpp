class Solution {
public:

    void next(vector<int>& h,vector<int>& nextSmaller){
        stack<int> st;
        st.push(-1);
        for(int i=h.size()-1;i>=0;i--){
            while( st.top()!=-1 && h[i] <= h[st.top()]) st.pop();
            nextSmaller[i]=st.top();
            st.push(i);
        }
        return;
    }
    void prev(vector<int>h,vector<int>& prevSmaller){
        stack<int> st;
        st.push(-1);
        for(int i=0;i<h.size();i++){
            while( st.top()!=-1 && h[i] <= h[st.top()]) st.pop();
            prevSmaller[i]=st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n= heights.size();
        vector<int>nextSmaller(n);
        vector<int>prevSmaller(n);
        next(heights,nextSmaller);
        prev(heights,prevSmaller);

        
        //IMP - ye hm isliye kr rhe kyuki nextSmaller me -1 hm tbhi dalte the jb rightside
        //me koi bhi smaller nhi hota tha
        for(int i=0;i<nextSmaller.size();i++){
            if(nextSmaller[i]==-1) nextSmaller[i]=nextSmaller.size();
        }

        vector<int> width(n);
        for(int i=0;i<n;i++){
            width[i]=nextSmaller[i]-prevSmaller[i]-1;
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int currentAns = width[i]*heights[i];
            ans = max(ans,currentAns);
        }
        return ans;
    }
};