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
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if(root==NULL) return {};
//         vector<vector<int>> ans;
//         vector<int> temp;

//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL);

//         while(!q.empty()){
//             TreeNode* frontNode = q.front();
//             q.pop();

//             if(frontNode != NULL){

//                 temp.push_back(frontNode->val);

//                 if(frontNode->left){
//                     q.push(frontNode->left);
//                 }
//                 if(frontNode->right){
//                     q.push(frontNode->right);
//                 }
//             }

//             if(frontNode == NULL){

//                 ans.push_back(temp);
//                 temp.clear();

//                 if(!q.empty()){
//                     q.push(NULL);
//                 }
//             }
//         }

//         //ans 2d array me level order tarversal pda h bs iski odd 
//         //position wale subarrays ko reverse kr diya to zig zag bn gya
//         for(int i=1;i<ans.size();i+=2){
//             reverse(ans[i].begin(), ans[i].end());
//         }
//         return ans;
//     }
// };



//soln-2
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> temp;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int level = 0;

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode != NULL){

                temp.push_back(frontNode->val);

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }

            if(frontNode == NULL){

                if(level % 2 == 1){//work likr flag
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                temp.clear();
                level++;

                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};