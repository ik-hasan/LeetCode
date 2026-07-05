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


//SOLN-1 BRUTE FORCE
// class Solution {
// public:
    
//     int height(TreeNode* root) {
//         if(root==NULL) return 0;
//         int ans1 = 1 + height(root->left);
//         int ans2 = 1 + height(root->right);
//         return max(ans1,ans2);

//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL) return true;

//         //hr node pr jakr height ka diff check kr rhe h, ek ka bhi diff >1 aaya to return false
//         bool leftAns = isBalanced (root->left);
//         bool rightAns = isBalanced (root->right);

//         if(leftAns == false || rightAns == false) return false;

//         int a = height(root->left);
//         int b = height(root->right);

//         if(abs(a-b)>1) return false;
//         return true;
//     }
// };



//SOLN-2 OPTIMIZED
class Solution {
public:

    bool balance = true;
    
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        int ans1 = 1 + height(root->left);
        int ans2 = 1 + height(root->right);

        if((abs(ans1-ans2)>1)){
            balance = false;
            return 0;
        }
        return max(ans1,ans2);

    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return balance;
    }
};