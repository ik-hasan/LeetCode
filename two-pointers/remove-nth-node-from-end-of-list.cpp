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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head ==NULL) return NULL;
        if(n==length(head)){
            ListNode* a = head;
            head = head->next;
            delete a;
            return head;
        }

        int  x= length(head)-n;
        ListNode* temp = head;
        while(x>1){
            temp = temp->next;
            x--;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return head;
    }
};