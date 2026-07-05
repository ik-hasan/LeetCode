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
    // ListNode* middleNode(ListNode* head) {
    //     ListNode* temp = head;

    //     int count = 0;
    //     while(temp!=NULL){
    //         count++;
    //         temp=temp->next;
    //     }

    //     ListNode* temp2 = head;
    //     int  x =0;
    //     if(count % 2 != 0 ) x= (count/2)+1;
    //     else x = (count/2);
    //     while(count != x){
    //         temp2=temp2->next;
    //         count--;
    //     }
    //     return temp2;
    // }

    //soln-2
    ListNode* middleNode(ListNode* head) {
        ListNode* kachua = head;
        ListNode* khargosh = head;

        while(khargosh!=NULL){
            khargosh = khargosh->next;
            if(khargosh) {
                khargosh = khargosh->next;
                kachua = kachua->next;
            }    
        }
        return kachua;
    }

};