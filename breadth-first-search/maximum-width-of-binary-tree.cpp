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
//     int width(TreeNode* root, int wid){
//         if(root==NULL){
//             return 1;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int x=0;
//             int size=q.size();
//             q.pop();
//             TreeNode* front=q.front();
//             for(int i=0;i<size;i++){
//                 x++;
//             }
//             wid=max(x,wid);
//             if(front->left!=NULL){
//                 q.push(front->left);
//             }
            
//             if(front->right!=NULL){
//                 q.push(front->right);
//             }
//         }
//         return wid;
//     }
//     int widthOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 1;
//         }
//         int wid=0;
//         return width(root,wid);
//     }
// };


class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {

        int maxWidth = 0;
        if(root==NULL){
            return maxWidth;
        }
        
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});

        while(!q.empty()){

            unsigned long long size = q.size();
            unsigned long long startIndex = q.front().second;
            unsigned long long endIndex = q.back().second;
            unsigned long long currentLevelWidth = endIndex - startIndex + 1;
            maxWidth=max(maxWidth,(int)currentLevelWidth);

            for(unsigned long long i=0;i<size;i++){
                auto front = q.front();
                q.pop();
                auto frontNode=front.first;
                auto index = front.second;
                if(frontNode->left){
                    q.push({frontNode->left,2*index});
                }
                if(frontNode->right){
                    q.push({frontNode->right,2*index+1});
                }
            }
        }
        return maxWidth;
    }
};
