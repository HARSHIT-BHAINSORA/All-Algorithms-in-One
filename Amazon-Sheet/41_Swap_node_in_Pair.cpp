
// Iterative approach

ListNode* swapPairs(ListNode* head) {
        
        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL)
        {
            swap(temp->val , temp->next->val);
            temp = temp->next->next;
        }

        return head;
    }

// Recursion Approach

ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;

        ListNode * nextNode = head->next->next;
        ListNode * newhead = head->next;
        
        head->next->next = head;
        head->next = swapPairs(nextNode);

        return newhead;    
    }