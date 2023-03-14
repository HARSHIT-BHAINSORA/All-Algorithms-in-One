class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *fast = head , *slow = head;

        while(n--)
            fast = fast->next;

        if(fast == NULL)
            return head->next;
        
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }    

        slow->next = slow->next->next;
        return head;
    }
};