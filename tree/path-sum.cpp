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
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==NULL) return false;
        // if(targetSum < 0 ) return false;
        // if(root->left == NULL && root->right==NULL && targetSum == 0) return true;
        // if(root->left==NULL && root->right == NULL && targetSum != 0) return false;

        if(root->left == NULL && root->right == NULL) {
            if(targetSum == root->val) return true;
            return false;
        }

        bool leftAns = false;
        bool rightAns = false;

        if(root->left) leftAns = hasPathSum(root->left,targetSum-root->val);
        if (root->right) rightAns = hasPathSum(root->right,targetSum-root->val);

        if(leftAns || rightAns) return true;
        return false;
    }
};