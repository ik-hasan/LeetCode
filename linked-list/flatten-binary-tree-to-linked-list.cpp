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
    void solve(TreeNode* root,TreeNode* &newRoot){
        if(root==NULL) return ;

        newRoot->left = NULL;
        newRoot->right = root;

        newRoot = newRoot->right;

        //ye hm store krke kyu call kr rhe ye smjh nhi aaya
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        solve(left,newRoot);
        solve(right,newRoot);

        //maine ye lines likhi thi bina store kiye call, but ye TLE mar rha pta nhi kyu ?
        // solve(root->left,newRoot);
        // solve(root->right,newRoot);

        return;

    }
    void flatten(TreeNode* root) {
        TreeNode dummy(-1);
        TreeNode* newRoot = &dummy;
        solve(root,newRoot);
        root=dummy.right;
    }
};