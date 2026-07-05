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


// class Solution {
// public:

//     int ans = 0;
//     void solve(long long target,TreeNode* root){
//         if(root==NULL) return;

//         if(root->val==target) ans++;

//         solve(target-root->val,root->left);
//         solve(target-root->val,root->right);
//         return;
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root==NULL) return 0;
    
//         pathSum(root->left,targetSum);
//         pathSum(root->right,targetSum);
        
//         solve(targetSum,root);
//         return ans;
//     }
// };


class Solution {
public:

    int ans = 0;
    void solve(long long target,TreeNode* root){
        if(root==NULL) return;

        if(root->val==target) ans++;

        solve(target-root->val,root->left);
        solve(target-root->val,root->right);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
    
        solve(targetSum,root);
        
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return ans;
    }
};
