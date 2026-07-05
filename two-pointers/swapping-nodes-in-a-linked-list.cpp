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
        if(!head) return 0;
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        int len = length(head);
        ListNode* temp = head;
        int a,b;
        for(int i=0;i<k-1;i++){
            temp = temp->next;
        }
        a=temp->val;

        ListNode* temp2 = head;
        for(int i=0;i<len-k;i++){
            temp2=temp2->next;
        }
        b=temp2->val;
        temp2->val = a;
        temp->val = b;
        return head;

    }
};