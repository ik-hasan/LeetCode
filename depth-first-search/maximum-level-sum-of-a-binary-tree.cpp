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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        int prevSum = INT_MIN;
        int level = 0;

        while(!q.empty()){

            level++;
            int Qsize = q.size();
            int currSum = 0;
            for(int i=0;i<Qsize;i++){
                TreeNode* frontNode = q.front();
                currSum += frontNode->val;
                q.pop();

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            if(currSum>prevSum){
                prevSum = currSum;
                ans = level;
            }
        }

        return ans;
    }
};