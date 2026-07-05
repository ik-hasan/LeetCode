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

    //soln-1 array me store krke krdunga brute force.


    //solne-2
    ListNode* reverseList (ListNode* head){
        if(head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    int length(ListNode* head){
        if(head == NULL) return 0;
        int count = 0;
        while(head != NULL){
            count++;
            head = head -> next;
        }
        return count;
    }


    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        ListNode* a = new ListNode(-1);
        ListNode* b = new ListNode(-1);
        ListNode* temp1 = a;
        ListNode* temp2 = b;

        int x = length(head)/2;

        while(temp!=NULL && x!=0){
            a->next = temp;
            temp=temp->next;
            a=a->next;
            x--;
        }
        a->next = NULL;

        while(temp!=NULL){
            b->next = temp;
            temp=temp->next;
            b=b->next;
        }
        b->next = NULL;

        ListNode* temp3 = reverseList(temp2->next);

        ListNode* ans = new ListNode(-1);
        ListNode* ans2 = ans;
        temp1 = temp1->next;

        while(temp1!=NULL || temp3!=NULL){
            if(temp1){
                ans->next = temp1;
                temp1=temp1->next;
                ans = ans->next;
            }
            if(temp3){
                ans->next = temp3;
                temp3=temp3->next;
                ans = ans->next;
            }
        }

        head = ans2->next;
    }
};