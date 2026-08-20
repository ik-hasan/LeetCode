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

    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l = root->val + solve(root->left);
        int r = root->val + solve(root->right);
        if(l<0 && r<0) return 0;
        ans = max(ans,l+r-root->val);
        return max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};