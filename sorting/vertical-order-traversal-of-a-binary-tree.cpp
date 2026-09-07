/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int col, int row, vector<tuple<int,int,int>> &nodes){
        if(root==NULL) return;

        nodes.push_back({col,row,root->val});
        solve(root->left,col-1,row+1,nodes);
        solve(root->right,col+1,row+1,nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<tuple<int,int,int>> nodes;
        solve(root,0,0,nodes);
        sort(nodes.begin(),nodes.end());

        vector<vector<int>> ans;
        int prevCol = INT_MIN;

        for(auto [col,row,val] : nodes){
            if(col == prevCol){
                ans.back().push_back(val);
            }
            else{
                ans.push_back({});
                prevCol = col;
                ans.back().push_back(val);
            }
        }
        return ans;
    }
};