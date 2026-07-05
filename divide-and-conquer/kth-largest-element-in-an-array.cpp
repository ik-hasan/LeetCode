class Solution {
public:
    //soln -1 basic
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> pq;
    //     for(auto x:nums) pq.push(x);

    //     for(int i=0;i<k-1;i++){
    //         pq.pop();
    //     }
    //     return pq.top();
    // }


    //soln - 2
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int> , greater<int>> pq;

        int j = 0;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
            j++;
        }
        for(int i=j;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};