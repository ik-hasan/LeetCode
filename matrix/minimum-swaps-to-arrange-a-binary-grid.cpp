class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        vector<int> last1;
        for(int i=0;i<grid.size();i++){
            int pos = -1;
            for(int j=grid[0].size()-1;j>=0;j--){
                if(grid[i][j]==1){
                    pos=j;
                    break;
                }
            }
            last1.push_back(pos);
        }

        //just for checking ki hm grid ko swap krke arrange kr skte h ya nhi
        //no use of this part of code in this problem
        // sort(last1.begin(),last1.end());
        // for(int i=0;i<last1.size();i++){
        //     if(last1[i]>i) return false;
        // }
        // return true;

        int n = last1.size();
        int swaps = 0;
        for(int i=0;i<n;i++){

            int j = i;

            while(j<n && last1[j] > i){
                j++;
            }

            if(j==n) return -1;

            while(j>i){
                swap(last1[j],last1[j-1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};