class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        ListNode *prev_p=NULL;
        ListNode *n;
        ListNode* curr=head;
        while(curr)
        {
            n=curr->next;
            curr->next=prev_p;
            prev_p=curr;
            curr=n;

        }
        head=prev_p;
        return head;
    }
