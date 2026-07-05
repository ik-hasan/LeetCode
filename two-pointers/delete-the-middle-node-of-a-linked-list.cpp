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
        if(head ==NULL) return 0;
        int count = 0;
        while(head){
            head = head->next;
            count ++;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL) return NULL;

        if(length(head)==1) return NULL;
        int len = length(head)/2;
        ListNode* temp = head;

        while(len>1){
            temp = temp->next;
            len--;
        }

        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        return head;
    }
};