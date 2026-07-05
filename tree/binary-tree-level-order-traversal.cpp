class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> temp;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

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

                ans.push_back(temp);
                temp.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};