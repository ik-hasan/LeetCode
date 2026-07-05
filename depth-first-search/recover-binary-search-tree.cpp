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
    void inorder(TreeNode* root,vector<int> &x){
        if(root==NULL) return;       

        inorder(root->left,x);
        x.push_back(root->val);
        inorder(root->right,x);
    }
    void putback(TreeNode* root,vector<int> &sortt,int &index){
        if(root==NULL) return;
        putback(root->left,sortt,index);
        root->val=sortt[index++];
        putback(root->right,sortt,index);
    }
    void recoverTree(TreeNode* root) {
        vector<int> x;
        inorder(root,x);

        vector<int> sortt = x;
        sort(sortt.begin(),sortt.end());

        int z=0;
        putback(root,sortt,z);
    }
};