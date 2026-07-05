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

    int length(ListNode* head){
        if(head==NULL) return false;

        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        int n = length(curr);
        if(n < k) return head;

        for(int i=0;i<k;i++){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};