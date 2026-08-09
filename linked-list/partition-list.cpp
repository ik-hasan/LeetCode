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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || x < -100 || x > 100) return head;

        ListNode *start1 = nullptr, *start2 = nullptr;
        ListNode *end1 = nullptr , *end2 = nullptr;

        while (head) {
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;

            if (x > temp->val) {
                if (start1 == nullptr) start1 = end1 = temp;
                else {
                    end1->next = temp;
                    end1 = temp;
                }
            }
            else {
                if (start2 == nullptr) start2 = end2 = temp;
                else {
                    end2->next = temp;
                    end2 = temp;
                }
            }
        }

        if (start1 && start2) {
            end1->next = start2;
            return start1;
        }
        else if (start1) return start1;
        else return start2;
    }
};