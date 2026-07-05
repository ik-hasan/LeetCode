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
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &preorderStart, int inorderStart,int inorderEnd){

        if(preorderStart >= preorder.size()) return NULL;
        if(inorderStart > inorderEnd) return NULL;

        int rootElement = preorder[preorderStart];
        preorderStart++;
        TreeNode* root = new TreeNode(rootElement);

        int x = 0;
        while(rootElement != inorder[x]){
            x++;
        }
        //x will pin to the rootElement in inorder array

        //first we'll call for left side bcz preorder - NLR
        root->left = solve(preorder,inorder,preorderStart,inorderStart,x-1);
        root->right = solve(preorder,inorder,preorderStart,x+1,inorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderStart = 0;
        return solve(preorder,inorder,preorderStart,0,inorder.size()-1); 
    }
};