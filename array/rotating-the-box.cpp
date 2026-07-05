class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int rows = box.size();
        int cols = box[0].size();
        // Apply gravity
        for (int r = 0; r < rows; r++) {

            int empty = cols - 1;
            for (int c = cols - 1; c >= 0; c--) {
                if (box[r][c] == '*') {
                    empty = c - 1;
                }
                else if (box[r][c] == '#') {

                    swap(box[r][c], box[r][empty]);
                    empty--;
                }
            }
        }
        // Rotate matrix
        vector<vector<char>> ans(cols, vector<char>(rows));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                ans[c][rows - 1 - r] = box[r][c];
            }
        }
        return ans;
    }
};