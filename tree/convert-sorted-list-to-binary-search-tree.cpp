/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* solve(vector<int> &v,int s,int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(v[mid]);

        root->left = solve(v,s,mid-1);
        root->right = solve(v,mid+1,e);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int> v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        int s=0,e=v.size()-1;
        return solve(v,s,e);
        // return NULL;
    }
};