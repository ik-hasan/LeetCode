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

    TreeNode* solve(vector<int>& nums,int st,int end){

        if(st>end) return NULL;

        int nodeIndex = (st+end)/2;

        TreeNode* root = new TreeNode(nums[nodeIndex]);

        root->left = solve(nums,st,nodeIndex-1);
        root->right = solve(nums,nodeIndex+1,end);

        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int st = 0,end = nums.size()-1;
        
        return solve(nums,st,end);
    }
};