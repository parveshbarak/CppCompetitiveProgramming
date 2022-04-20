class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==0)
            return NULL;
        if(head->next==0)
            return head;
        
        
        ListNode *a=head;
        ListNode *b=a->next;
        ListNode *newhead=b;
        ListNode *prev=a;
        while(a && b)
        {
            prev=a;
            a->next=b->next;
            b->next=prev;
            
            a=a->next;
            if(a!=0 && a->next!=0)
             b=a->next;
            else
                break;
            prev->next=b;
            
        }
        return newhead;
        
    }
};