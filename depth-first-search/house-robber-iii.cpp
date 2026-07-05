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
    // int solve(TreeNode* root){
    //     if(root==NULL) return 0;

    //     int inc = root->val;
    //     if(root->left) inc = inc + solve(root->left->left) + solve(root->left->right);
    //     if(root->right) inc = inc + solve(root->right->left) + solve(root->right->right);
    //     int exc = solve(root->left) + solve(root->right);

    //     return max(exc,inc);
    // }
    // int rob(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     return solve(root);
    // }



    //MEMOIZATION
    int solve(TreeNode* root,unordered_map<TreeNode*, int> &dp){
        if(root==NULL) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        int inc = root->val;
        if(root->left) inc = inc + solve(root->left->left,dp) + solve(root->left->right,dp);
        if(root->right) inc = inc + solve(root->right->left,dp) + solve(root->right->right,dp);
        int exc = solve(root->left,dp) + solve(root->right,dp);

        dp[root] = max(exc,inc);
        return dp[root];
    }
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        unordered_map<TreeNode*, int> dp;
        return solve(root,dp);
    }
};