class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negValues = 0;
        int lowestNegValue = INT_MAX;

        for(auto &i : matrix){
            for(auto &j : i){
                if(j<0) negValues++;
                sum += abs(j);
                lowestNegValue = min(lowestNegValue,abs(j));
            }
        }

        if(negValues % 2 == 0) return sum;

        return sum-2LL*lowestNegValue; //Jahan long long result chahiye,kam se kam ek operand LL(long long) hona chahiye
    }
};