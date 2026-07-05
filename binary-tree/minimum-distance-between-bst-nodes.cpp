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
    vector<int> x;
    int minm(vector<int> y){
        int a = y[0];
        for(int i=1;i<y.size();i++){
            if(y[i] < a){
                a=y[i];
            }
        }
        return a;
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        x.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        vector<int> y;
        for(int i=1;i<x.size();i++){
            y.push_back(x[i]-x[i-1]);
        }
        return minm(y);
    }
};