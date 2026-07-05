/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        if(head==NULL) return NULL;
        Node* temp = head;
        Node* tail = temp;
        while(temp){
            if(temp->child){
                Node* temp3 = temp->next;
                temp->next = temp->child;
                temp->next->prev = temp;
                Node* temp2 = solve(temp->child);
                temp2->next = temp3;
                if(temp3) temp3->prev=temp2;
                temp->child = NULL;
            }
            tail= temp;
            temp = temp->next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};