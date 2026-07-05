class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto it:arr){
            int count = 0;
            int elem = it;
            while(it>0){
                it = it & (it-1);
                count++;
            }
            minHeap.push({count,elem});
        }
        vector<int> ans;
        while(!minHeap.empty()){
            auto topp = minHeap.top();
            minHeap.pop();
            int elem = topp.second;
            ans.push_back(elem);
        }
        return ans;
    }
};