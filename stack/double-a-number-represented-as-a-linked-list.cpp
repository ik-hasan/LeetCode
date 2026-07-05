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
    ListNode* reverseList(ListNode* head){
        if(!head) return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        
        head = reverseList(head);
        ListNode* temp = head;
        int carry = 0;
        while(temp){
            int sum = (2*temp->val) + carry;
            carry = sum / 10;
            temp->val = sum % 10;
            if(temp->next == NULL && carry != 0){
                ListNode* newNode = new ListNode(carry);
                newNode->next = NULL;
                temp->next = newNode;
                temp = newNode;
            }
            temp = temp->next;
        }
        head = reverseList(head);
        return head;
    }
};