class Solution {
public:
    void sanitize(ListNode* head, unordered_map<int,ListNode*> &mp, int currentSum){
        int temp = currentSum;
        while(head){
            temp += head->val;
            if(temp == currentSum) break;
            mp.erase(temp);
            head = head->next;
        }
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int,ListNode*> mp; 
        int currentSum = 0;
        ListNode* temp = dummy;
        
        while(temp){
            currentSum += temp->val;
            if(mp.find(currentSum) != mp.end()){
                ListNode* start = mp[currentSum];
                sanitize(start->next, mp, currentSum);
                start->next = temp->next;
            } else {
                mp[currentSum] = temp;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};