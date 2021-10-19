/*
 Merge Two Sorted Linked List 
*/


/*  Method 1   time : O(n + m)  space : O(n  + m)  */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    
    if(NULL == l1) return l2;
    if(NULL == l2) return l1;
    
    ListNode* head=NULL;    // head of the list to return
    
    // find first element (can use dummy node to put this part inside of the loop)
    if(l1->val < l2->val)       { head = l1; l1 = l1->next; }
    else                        { head = l2; l2 = l2->next; }
    
    ListNode* p = head;     // pointer to form new list
    
    // I use && to remove extra IF from the loop
    while(l1 && l2){
        if(l1->val < l2->val)   { p->next = l1; l1 = l1->next; }
        else                    { p->next = l2; l2 = l2->next; }
        p=p->next;
    }
    
    // add the rest of the tail, done!
    if(l1)  p->next=l1;
    else    p->next=l2;
    
    return head;
}


/*  Method 1   time : O(n + m)  space : O(1)  */


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val > l2->val) swap(l1,l2);
        ListNode * res = l1;
        
        while(l1!=NULL and l2!=NULL)
        {
             ListNode * curr = NULL;
             
            while(l1!=NULL and l1->val <=l2-nval)
            {
                curr  = l1;
                l1 = l1->next;
            }
            
            curr->next = l2;
            
            swap(l1,l2);
        }
        
        return res;
        
        
    }
