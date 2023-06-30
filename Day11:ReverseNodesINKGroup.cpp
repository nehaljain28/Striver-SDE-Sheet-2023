class Solution {
public:
    int count(ListNode* head) {
        if (!head) return 0;
        
        int c = 0;
        while (head) {
            c++;
            head = head->next;
        }
        
        return c;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = NULL;
        ListNode* next, *curr = head;
        
        int c = count(head);
        if (c < k || !head)
            return head;
        
        int n = k;
        while (curr && n--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if (head) {
            head->next = reverseKGroup(next, k);
        }
        
        return prev;
    }
   
};
