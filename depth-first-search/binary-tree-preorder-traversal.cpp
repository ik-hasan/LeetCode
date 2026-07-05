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

    void preorder(TreeNode* root,vector<int>& result){
        if(root==NULL){
            return;
        }
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> x;
        if(root==NULL){
            return x;
        }
        // x.push_back(root->val);
        // vector<int> left = preorderTraversal(root->left);
        // vector<int> right = preorderTraversal(root->right);

        // x.insert(x.end(),left.begin(),left.end());
        // x.insert(x.end(),right.begin(),right.end());
        preorder(root,x);
        return x;
    }
};