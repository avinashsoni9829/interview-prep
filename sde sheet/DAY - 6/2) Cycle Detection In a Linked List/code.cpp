Cycle in  a Linked List 



Using Floyd's  Tortoise and Hare Algorithm :
	


bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL)
            return false;
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(slow!=fast)
        {
            if(fast==NULL or fast->next==NULL)
                return false;
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return true;
        
    }
    
    
    // can use hashet
    
    // can use -1 indexing 
    
    
