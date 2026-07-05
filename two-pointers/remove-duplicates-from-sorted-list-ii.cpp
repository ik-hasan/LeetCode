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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* prev = NULL;     
        ListNode* temp = head;

        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                int dupVal = temp->val;

                while (temp && temp->val == dupVal) {
                    ListNode* del = temp;
                    temp = temp->next;
                    delete del;   
                }
                if (prev == NULL) {
                    head = temp;   
                } else {
                    prev->next = temp;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

