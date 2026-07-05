class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int row=matrix.size();
        int col=matrix[0].size();

        int count=0;
        int total=row*col;

        int startingrow=0;
        int startingcol=0;
        int lastcol=col-1;
        int lastrow=row-1;


        while(count < total){

            //first row
            for(int index=startingcol; count < total && index<=lastcol; index++){
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++;

            //last col
            for(int index=startingrow; count < total &&  index<=lastrow; index++){
                ans.push_back(matrix[index][lastcol]);
                count++;
            }
            lastcol--;

            //last row
            for(int index=lastcol; count < total &&  index>=startingcol; index--){
                ans.push_back(matrix[lastrow][index]);
                count++;
            }
            lastrow--;

            //first col
            for(int index=lastrow; count < total && index>=startingrow; index--){
                ans.push_back(matrix[index][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans;
    }
};