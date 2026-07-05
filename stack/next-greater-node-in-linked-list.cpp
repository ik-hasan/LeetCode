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
class Solution {
public:
    pair<int,vector<int>> solve(ListNode* head){
        int a = 0;
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            a++;
            head = head->next;
        }
        return {a,temp};
    }
    vector<int> nextLargerNodes(ListNode* head) {
        auto x = solve(head);
        int n = x.first;
        auto arr = x.second;

        vector<int> ans(n,0);
        stack<int> st;
        st.push(0);

        for(int i=arr.size()-1;i>=0;i--){
            while(st.top()!=0 && arr[i]>=st.top()) st.pop();
            ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};