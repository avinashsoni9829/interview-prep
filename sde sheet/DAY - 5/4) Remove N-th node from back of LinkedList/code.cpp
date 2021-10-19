/*  Delete Nth Node from a linked list  */

1 .  time :  O(2 * N)
     space :  O(1)
     
     int len(ListNode *  head)
    {
       int ans = 0;
        
        while(head)
        {
          ans = ans + 1;
            head = head ->next;
        }
        
        return ans;
        
    }
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
      ListNode *  ans = head;
        ListNode *  curr = head;
        
        int req = len(head) - n;
        
        if(req == 0)
        {
          return  ans->next;
            
        }
        
        int counter  = 0;
        cout<<"counter : "<<counter<<endl;
        cout<<"req :  "<<req<<endl;
        
        while(counter<req-1)
        {
            counter = counter + 1;
            curr = curr ->next;
        }
        
       
        curr -> next = curr->next->next;
       
        return ans;
        
    }
    
    
    
2. Time : O(N)  space : O(1)

     ListNode* removeNthFromEnd(ListNode* head, int n) {
    
     ListNode *  ans = new ListNode();
     ans -> next = head;
        
     ListNode *  fast = ans;
     ListNode * slow = ans;
        
        for(int i = 0 ; i<=n-1;++i) fast = fast -> next;
        
        while(fast->next != NULL)
        {
           fast = fast -> next ;
           slow = slow -> next ;
            
        }
        
        slow -> next = slow ->next ->next ;
        
        return ans->next;
        
        
        
    }
  
