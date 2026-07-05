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
    void inorder(TreeNode* root,vector<TreeNode*> &vec){
        if(root==NULL) return;

        inorder(root->left,vec);
        vec.push_back(root);
        inorder(root->right,vec);
    }

    TreeNode* createTree(vector<TreeNode*> vec,int p,int q){
        if(p>q) return NULL; 

        TreeNode* n1 = NULL;

        int mid = (p+q)/2;
        n1 = vec[mid];

        n1->left = createTree(vec,p,mid-1);
        n1->right = createTree(vec,mid+1,q);

        return n1;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vec;
        inorder(root,vec);
 
        return createTree(vec,0,vec.size()-1);
    }
};