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
    //BRUTE FORCE
    // vector<int> x;
    // void solve(TreeNode* root){
    //     if(root==NULL){
    //         return;
    //     }
    //     solve(root->left);
    //     x.push_back(root->val);
    //     solve(root->right);
    // }
    // bool isValidBST(TreeNode* root) {
    //     solve(root);
    //     for(int i=1;i<x.size();i++){
    //         if(x[i]<=x[i-1]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }


    //OPTIMIZE
    bool solve(TreeNode* root, long long lb, long long ub){
        if(root==NULL){
            return true;
        }

        bool currentNode = root->val > lb && root->val < ub;

        bool leftAns = solve(root->left,lb,root->val);
        bool rightAns = solve(root->right,root->val,ub);

        return currentNode && leftAns && rightAns;
    }

    bool isValidBST(TreeNode* root){
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;
        return solve(root,lb,ub);
    }
};