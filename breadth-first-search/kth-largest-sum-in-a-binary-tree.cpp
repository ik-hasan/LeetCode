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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        int level = 0;

        while(!q.empty()){
            level++;
            int Qsize = q.size();
            long long currSum = 0;
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
            ans.push_back(currSum);
        }
        if(k>level) return -1;

        sort(ans.rbegin(),ans.rend());
        return ans[k-1];
    }
};