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
// class Solution {
// public:
    
//     ListNode* reverseBetween(ListNode* head, int left, int right) {

//         if(head==NULL || head->next == NULL) return head;

//         ListNode* curr = head;
//         ListNode* n = curr->next;

//         while(n && n->val != left){
//             curr = n;
//             n=n->next;
//         }
//         //curr hmara left ke phle wale ke ooper aa chuka h

//         ListNode* y = n;
//         ListNode* x = n;
//         ListNode* prev = NULL;
//         ListNode* nn = x->next;

//         while(x->val!=right && nn!=NULL){
//             x->next = prev;
//             prev=x;
//             x=nn;
//             nn=nn->next;
//         }
//         x->next = prev;
//         prev=x;
//         x=nn;
//         nn=nn->next;
//         curr->next = prev;
//         y->next = x;
//         return head;
//     }
// };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to the node just before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* nxt = nullptr;

        // Reverse nodes from left to right
        for (int i = 0; i < right - left; i++) {
            nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }

        return dummy.next;
    }
};
