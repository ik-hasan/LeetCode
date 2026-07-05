class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            cout<<endl;
        }

        for(int i=0;i<row;i++){
            int s=0,end=col-1;
            while(s<=end){
                swap(matrix[i][s],matrix[i][end]);
                s++;
                end--;
            }
        }
    }
};