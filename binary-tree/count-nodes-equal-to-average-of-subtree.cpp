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
    int ans = 0;
    auto solve(TreeNode* root){
        if(root==NULL) return make_pair(0,0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        int nodes = 1 + left.first + right.first;
        int totalSum = root->val + left.second + right.second;
        if(totalSum/nodes == root->val) ans++;
        
        return make_pair(nodes,totalSum);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};