class Solution {
public:

    bool solve(vector<int>& m,vector<int> &sides,int index){
        // base case
        if(index>=m.size()){
            if(sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0) return true;
            return false;
        }

        bool ans = false;

        for(int i=0;i<4;i++){
            if(sides[i] < m[index]) continue;
            else if(sides[i] >= m[index]){
                sides[i] -= m[index];
                ans = solve(m,sides,index+1);
                if(ans) return true;
                sides[i] += m[index];
            }
        }
        return ans;
    }
    bool makesquare(vector<int>& m) {
        int totalSum = accumulate(m.begin(),m.end(),0);
        if(totalSum % 4 != 0) return false;
        int target = totalSum/4;
        sort(m.rbegin(),m.rend());
        vector<int> sides(4,target);
        return solve(m,sides,0);
    }
};