class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        
        queue<vector<int>> q;
        q.push(nums1);
        map<vector<int>,int> dist;
        dist[nums1]=0;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr==nums2) return dist[curr];
            int n = curr.size();

            for(int L=0;L<n;L++){
                for(int R=L;R<n;R++){
                    vector<int> subArr(curr.begin()+L,curr.begin()+R+1);

                    vector<int> rem;
                    for(int i =0;i<n;i++){
                        if(i<L || i>R) rem.push_back(curr[i]); 
                    }

                    for(int pos = 0;pos<rem.size();pos++){
                        vector<int> next = rem;
                        next.insert(next.begin()+pos,subArr.begin(),subArr.end());

                        if(next == nums2) return dist[curr] + 1;
                        if(!dist.count(next)){
                            q.push(next);
                            dist[next] = dist[curr]+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};