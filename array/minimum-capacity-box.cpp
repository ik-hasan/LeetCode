class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minDiff = INT_MAX;
        int ans = -1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i] >= itemSize){
                int currDiff = capacity[i]-itemSize;
                if(currDiff < minDiff ){
                    minDiff = currDiff;
                    ans = i;
                }
            }
        }
        return ans;
    }
};