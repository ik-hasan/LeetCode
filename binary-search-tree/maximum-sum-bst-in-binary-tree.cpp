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
 class info{
    public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
 };
class Solution {
public:
    int minm(int a, int b, int c){
        int minAns = min(a,min(b,c));
        return minAns;
    }
    int maxm(int a, int b, int c){
        int maxAns = max(a,max(b,c));
        return maxAns;
    }
    info solve(TreeNode* root,int &sum){
        if(root==NULL){
            info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum=max(sum,temp.sum);
            return temp;
        }
        if(root->left == NULL && root->right == NULL){
            info temp;
            temp.minVal = root->val;
            temp.maxVal = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            sum=max(sum,temp.sum);
            return temp;
        }

        info leftAns = solve(root->left,sum);
        info rightAns = solve(root->right,sum);

        info currentAns;

        currentAns.minVal = minm(leftAns.minVal,rightAns.minVal,root->val);
        currentAns.maxVal = maxm(leftAns.maxVal,rightAns.maxVal,root->val);
        currentAns.sum = root->val + leftAns.sum + rightAns.sum;
        currentAns.isBST = (root->val < rightAns.minVal && root->val > leftAns.maxVal && leftAns.isBST && rightAns.isBST );

        if(currentAns.isBST){
            sum=max(sum,currentAns.sum);
        }
        return currentAns;
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        info temp = solve(root,sum);
        return sum;
    }
};