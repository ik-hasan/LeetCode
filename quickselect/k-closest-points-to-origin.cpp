class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue< pair<long long, pair<int,int>>,
                        vector<pair<long long, pair<int,int>>>,
                        greater<pair<long long, pair<int,int>>> > pq;
        for(auto x: points){
            int adhar = x[0];
            int lamb = x[1];
            int karn = adhar*adhar + lamb*lamb;
            pq.push({karn,{adhar,lamb}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            auto front = pq.top();pq.pop();
            ans.push_back({front.second.first,front.second.second});
        }
        return ans;
    }
};

