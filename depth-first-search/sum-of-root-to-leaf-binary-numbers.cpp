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

    int solve2(vector<int> &temp){
        int ans = 0;
        int t=1;
        for(int i=temp.size()-1;i>=0;i--){
            ans+=t*temp[i];
            t=t*2;
        }
        return ans;
    }
    void solve(TreeNode* root,vector<int> &temp,vector<vector<int>> &temp2){
        if(!root) return;   

        temp.push_back(root->val);

        if(!root->left && !root->right){
            temp2.push_back(temp);
        }
        solve(root->left,temp,temp2);
        solve(root->right,temp,temp2);
        temp.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> temp2;
        solve(root,temp,temp2);
        int ans = 0;
        for(auto it:temp2){
            ans += solve2(it);
        }
        return ans;
    }
};