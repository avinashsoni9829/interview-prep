/*  Middle of a Linked List  */

1 .  count nodes and return the corresponding node 


int count = 0 ;

void  CntNode(Node * root)
{
      while(root!=NULL)
      {
      	   count =  count + 1;
      	   root = root ->next;
	  }
    	  
}


Node *  middle(Node * root)
{
   CntNode(root);
   int target ; 
   int curr = 0 ;
   if(count % 2 == 0)
   {
   	   target = count / 2;
   }
   else
   {
   	   target = count / 2 + 1;
   }
   Node  * ans  = head;
   while(curr!=target)
   {
   	    ans  = ans -> next;
   	   curr = curr + 1;
   }
   
   return ans;
   
    	  
}




2. Using Slow and Fast Pointer 


  Node*  middle (Node *  root)
  {
  	  Node * slow = root;
  	  Node * fast = root;
  	  
  	  while(fast!=NULL and fast->next!=NULL)
  	  {
  	     
		    fast = fast->next->next;	  
	        slow = slow->next;
	  }
	  
	  return slow;
  }
  
  
  
