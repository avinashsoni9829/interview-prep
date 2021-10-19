/*  add two number given as linked list  */ 

time  :  O(max : (l1.length , l2.length))
space  : O(1)
--------------------------------------------------------------------------------------------
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode  *  ans = new  ListNode ();
        
        ListNode  * curr = ans;
        
        int carry = 0;
        
        while(l1!=NULL or l2!=NULL or carry)
        {
            int sum = 0;
            
            if(l1!=NULL)
            {
                sum = sum + l1->val;
                l1  = l1 -> next;
            }
            
            if(l2!=NULL)
            {
               sum = sum  + l2->val;
                l2 = l2 -> next;   
            }
            
            sum = sum + carry ;
            
            carry = sum / 10 ;
            
            ListNode *  nd = new ListNode(sum%10);
            
            curr->next = nd;
            curr = nd;

            
        }
        
        return ans -> next ;
        
        
    }

