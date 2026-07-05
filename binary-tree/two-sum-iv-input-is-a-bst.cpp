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
    void storeInorder(TreeNode* root,vector<int> &vec){
        if(root==NULL){
            return;
        }
        storeInorder(root->left,vec);
        vec.push_back(root->val);
        storeInorder(root->right,vec);
    }
    bool checkTwoSum(vector<int> vec,int target){
        int size=vec.size();
        int s=0,e=size-1;
        while(s<e){
            int sum = vec[s]+vec[e];
            if(sum == target){
                return true;
            }
            if(sum > target){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        vector<int> inorder;
        storeInorder(root,inorder);
        return checkTwoSum(inorder,k);
    }
};