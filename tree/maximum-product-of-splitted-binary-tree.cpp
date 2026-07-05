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
    long long mod = 1000000007;
    long long totalTreeSum = 0;
    long long ans = 0;

    long long totalSum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    // int subTreeSum(TreeNode* root){
    //     if(root==NULL) return 0;

    //     return root->val + subTreeSum(root->left) + subTreeSum(root->right);
    // }

    long long  solve(TreeNode* root){
        if(root==NULL) return 0;

        long long left = solve(root->left);
        long long right = solve(root->right);

        long long subTreeSum = root->val + left + right;
        ans = max(ans,(subTreeSum*(totalTreeSum-subTreeSum)));

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
        totalTreeSum = totalSum(root);
        solve(root);
        return ans % mod;
    }
};