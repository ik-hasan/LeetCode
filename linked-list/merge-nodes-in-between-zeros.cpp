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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* temp = head->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(temp){
            long long sum = 0;
            while(temp->val != 0){
                sum += temp->val;
                temp=temp->next;
            }
            curr->next = new ListNode(sum);
            curr=curr->next;
            temp=temp->next;
        }
        curr->next = NULL;

        return dummy->next;
    }
};