/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* curr = dummy;

        unordered_map<Node*,Node*> mp;//VERY IMP

        while(temp){
            curr->next = new Node(temp->val);
            curr=curr->next;
            mp[temp] = curr;//ACTUAL LL KE NODES KI MAPPING NEW LL KE NODES SE
            temp = temp->next;
        }

        Node* temp2 = dummy->next;
        dummy=dummy->next;
        while(dummy){
            dummy->random = mp[head->random];//IMP
            dummy=dummy->next;
            head = head->next;
        }
        return temp2;
    }
};