find the point where cycle begins 


1.  use set and see if it occurs again   time : O(n) space : O(n)





2.  floyds cycle detection  and restarting from slow and fast to find the point of contact 
   time : O(n)
   space : O(1)
   
   
   
   class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        
		if(head==NULL or head->next==NULL) return NULL;
        
		ListNode *slow = head;
        ListNode *fast = head;
        
		while(fast!=NULL and fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        
		if(fast==NULL or fast->next==NULL) return NULL;
        
		slow = head;
        
		while(fast!=slow) {
            fast = fast->next;
            slow=slow->next;
        }
        
		return slow;
    }
};  
