// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         int n = nums.size()-k+1;
//         int z=0;
//         vector<int> ans(n);
//         for(int i=0;i<=nums.size()-k;i++){
//             int maxx = INT_MIN;
//             for(int j=i;j<k+i;j++){
//                 maxx = max(maxx,nums[j]);
//             }
//             // ans.push_back(maxx);
//             ans[z++]=maxx;
//         }
//         return ans;
//     }
// };




// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         queue<int> q;
//         int maxx = INT_MIN;
//         vector<int> ans;

//         //process first window
//         int idx = 0;
//         for(int i=0;i<k;i++){
//             if(nums[i]>maxx){
//                 maxx=nums[i];
//                 idx=i;
//             }
//         }
//         q.push(idx);
    
//         //process remaining window
//         for(int i=k;i<nums.size();i++){
//             //make ans
//             ans.push_back(nums[q.front()]);

//             //removal
//             if(!q.empty() && i-q.front()>=k){
//                 q.pop();
//             }
//             //addition
//             if(!q.empty()){
//                 if(nums[q.front()] < nums[i]){
//                     q.pop();
//                     q.push(i);
//                 }
//             }
//             else{
//                 // recalculate max in current window
//                 int newMax = nums[i-k+1];
//                 int idx = i-k+1;
                
//                 for(int j=i-k+1;j<=i;j++){
//                     if(nums[j] >= newMax){
//                         newMax = nums[j];
//                         idx = j;
//                     }
//                 }
//                 q.push(idx);
//             }
//         }
//         ans.push_back(nums[q.front()]);
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //process first window 
        for(int i=0; i<k; i++) {
            int element = nums[i];
            
            while(!dq.empty() && nums[dq.back()] < element) {
                dq.pop_back();
            }
            //current element toh insert krna hi h
            dq.push_back(i);
        }

        //get answer for first window 
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);

        //process remaining windows 
        for(int i=k; i<nums.size(); i++) {
            //removal
            if(!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }
            //addition
            int element = nums[i];
            
            while(!dq.empty() && nums[dq.back()] < element) {
                dq.pop_back();
            }
            //current element toh insert krna hi h
            dq.push_back(i);

            //ans store
            int index = dq.front();
            int ansElement = nums[index];
            ans.push_back(ansElement);
        }
        return ans;
    }
};