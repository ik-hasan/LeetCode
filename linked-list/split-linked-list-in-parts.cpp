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
    int length(ListNode* head){
        if(head == NULL) return 0;
        int count = 0;
        while(head){
            head = head ->next;
            count ++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = length(head);

        int partSize = n/k;
        int extraNodes = n % k;

        ListNode* temp = head;

        vector<ListNode*> ans(k,NULL);

        for(int i = 0;i<k && temp; i++){
            ans[i]=temp;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            for(int j=0;j<currentPartSize - 1; j++){
                temp = temp->next;
            }

            ListNode* a = temp->next;
            temp->next = NULL;
            temp = a;
        }
        return ans;
    }
};