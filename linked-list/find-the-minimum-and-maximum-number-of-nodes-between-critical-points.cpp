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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        vector<int> v;
        if(head == NULL) return ans;
        ListNode* temp = head;
        ListNode* temp2 = temp->next;
        int count = 2;

        while(temp2 && temp2->next){
            if(  (temp2->val > temp->val && temp2->val > temp2->next->val) || (temp2->val < temp->val && temp2->val < temp2->next->val)  ){
                v.push_back(count);
            }
            count++;
            temp=temp2;
            temp2 = temp2->next;
        }

        int size = v.size();
        if(size<2) return ans;
        int smallestDist = v[1]-v[0];
        for(int i = 1;i<size;i++){
            int x = v[i]-v[i-1];
            smallestDist = min(smallestDist,x);
        }
        ans[0]=smallestDist;
        ans[1]=v[size-1]-v[0];
        return ans;
    }
};