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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int& postEnd,int inorderStart, int inorderEnd){
        if(postEnd < 0) return NULL;
        if(inorderStart > inorderEnd) return NULL;

        int rootElement = postorder[postEnd];
        postEnd--;
        TreeNode* root = new TreeNode(rootElement);

        int x = 0;
        while(rootElement != inorder[x]){
            x++;
        }
        //x will pin to the rootElement in inorder array

        //first we'll call for right side bcz postorder - LRN
        root->right = solve(inorder,postorder,postEnd,x+1,inorderEnd);
        root->left = solve(inorder,postorder,postEnd,inorderStart,x-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postEnd = postorder.size()-1;
        return solve(inorder,postorder,postEnd,0,inorder.size()-1);
    }
};