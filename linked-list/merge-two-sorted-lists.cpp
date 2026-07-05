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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2; 
        if(list2==NULL) return list1; 
        // ListNode* temp=list1;
        // while(temp->next!=NULL){
        //     temp=temp->next;
        // }
        // temp->next=list2;
        // temp = list1;
        // vector<int> vals;
        // while(temp!=NULL){
        //     vals.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(vals.begin(),vals.end());

        // temp = list1;
        // int i=0;
        // while(temp!=NULL){
        //     temp->val=vals[i++];
        //     temp=temp->next;
        // }
        
        // return list1;
        ListNode dummy(-1);
        ListNode* x = &dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                x->next = list1;
                list1=list1->next;
            }
            else{
                x->next=list2;
                list2=list2->next;
            }
            x=x->next;
        }
        if(list1){
            x->next=list1;
        }
        else{
            x->next=list2;
        }
        return dummy.next;
    }
};