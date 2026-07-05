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
//     void inorderStore(TreeNode* root, vector<int> &inorder){
//         if(root==NULL){
//             return;
//         }
//         inorderStore(root->left,inorder);
//         inorder.push_back(root->val);
//         inorderStore(root->right,inorder);
//     }
//     void updateInorderTraversal(TreeNode* root,vector<int> &inorder,int &index){
//         if(root==NULL){
//             return;
//         }
//         updateInorderTraversal(root->left,inorder,index);
//         root->val=inorder[index];
//         index++;
//         updateInorderTraversal(root->right,inorder,index);
//     }
//     TreeNode* convertBST(TreeNode* root) {
//         if(root==NULL){
//             return NULL;
//         }
//         if(root->left==NULL && root->right==NULL){
//             return root;
//         }
//         vector<int> inorder;  
//         inorderStore(root,inorder);

//         int n=inorder.size();
//         for(int i = n-2;i>=0;i--){
//             inorder[i]=inorder[i]+inorder[i+1];
//         }

//         int index=0;
//         updateInorderTraversal(root,inorder,index);
//         return root;
//     }
// };


//2nd SOLUTION

class Solution {
public:
    // int sum = 0;

    void reverseInorder(TreeNode* root,int &sum) {
        if (!root) return;

        reverseInorder(root->right,sum);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left,sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        reverseInorder(root,sum);
        return root;
    }
};