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

    bool solve(TreeNode* rootL,TreeNode* rootR){
        if(rootL==NULL && rootR==NULL) return true;
        if( (rootL==NULL && rootR!=NULL) || (rootL!=NULL && rootR==NULL) ) return false;
        if(rootL->val != rootR->val) return false;

        bool left = solve(rootL->left, rootR->right);
        bool right = solve(rootL->right, rootR->left);


        if(left==false || right==false)  return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;

        return solve(root->left,root->right);
    }
};