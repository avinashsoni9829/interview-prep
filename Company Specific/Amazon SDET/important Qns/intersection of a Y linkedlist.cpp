// find intersection point of a linked list


3. Using the length of linked list difference and simulatenous travel    time : O(2 * M)  space : O(1)
   
   
class Solution {
public:
    
    int len  (ListNode * ll)
    {
         int ans = 0;
        
          while(ll)
          {
               ans = ans + 1;
               ll = ll -> next;
          }
        
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        int n = len(headA);
        int m = len(headB);
        
        ListNode * A  = headA;
        ListNode * B  = headB;
        
        if(n>m)
        {
             int diff = n - m ;
             while(diff--)
             {
               A = A -> next;   
             }
             
        }
        else
        {
             int diff = m - n ;
             while(diff--)
             {
               B = B -> next;   
             } 
            
        }
        
        
        while(A!=NULL or B!=NULL)
        {
             if(A == B)  return A;
             A = A -> next;
             B = B -> next;
            
            
        }
        
        return NULL;
        
     
    }
};






4.  Using Dummy Nodes and simulatenous Travel    time : O(2 * M)  space : O(1)

    class Solution {
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
	   if(headA == NULL or headB == NULL) return NULL;
        
        ListNode * A = headA;
        ListNode * B = headB;
        
        while(A!=B)
        {
           A =  A == NULL ? headB : A -> next;
           B =  B == NULL ? headA : B -> next;
        }
        
        return A;
     
    }
};

