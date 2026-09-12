/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;

        auto a = solve(root->left,p,q);
        auto b = solve(root->right,p,q);
        return  NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;
        auto a = solve(root->left,p,q);
        auto b = solve(root->right,p,q);
        if(a!=NULL && b!=NULL) return root;
        else if(a!=NULL && b==NULL) return a;
        return b;
    }
};