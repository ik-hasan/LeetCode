class Solution {
public:

    void solve(TreeNode* root, int row, int col, vector<tuple<int,int,int>>& nodes) {

        if(root == NULL) return;

        nodes.push_back({col, row, root->val});

        solve(root->left, row + 1, col - 1, nodes);
        solve(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<tuple<int,int,int>> nodes;
        solve(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;

        int prevCol = INT_MIN;
        for(auto [col, row, val] : nodes) {
            if(col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};