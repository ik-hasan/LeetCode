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

    //soln-1
    // ListNode* reverseList(ListNode* head) {
    //     if(head==NULL) return NULL;
    //     ListNode* curr = head;
    //     ListNode* aage = curr->next;
    //     ListNode* prev = NULL;

    //     while(aage!=NULL){
    //         curr->next = prev;
    //         prev=curr;
    //         curr = aage;
    //         aage = aage->next;
    //     }
    //     curr->next = prev;
    //     return curr;
    // }


    //soln-2
    // ListNode* reverseList(ListNode* head) {
    //     if(head==NULL) return NULL;
    //     ListNode* aage = head->next;
    //     ListNode* prev = NULL;

    //     while(aage!=NULL){
    //         head->next = prev;
    //         prev=head;
    //         head = aage;
    //         aage = aage->next;
    //     }
    //     head->next = prev;
    //     return head;
    // }


    //soln-3

    ListNode* solve(ListNode* &prev,ListNode* &curr,ListNode* &aage){
        if(aage==NULL) return prev;

        // ListNode* aage = curr->next;
        curr -> next = prev;
        prev= curr;
        curr=aage;
        aage=aage->next;

        return solve(prev,curr,aage);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* curr = head;
        ListNode* aage = curr->next;
        ListNode* prev = NULL;

        ListNode* ans = solve(prev,curr,aage);
        curr->next = ans;
        return curr;
    }
};