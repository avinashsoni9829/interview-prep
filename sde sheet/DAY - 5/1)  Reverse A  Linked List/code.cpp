

1 . Reverse A  linked List Using Iterative Method  : Time : O(n)  + Space : O(1);
    
    /*
       time : O(n)
       space : O(1)
    */
    Node * reverseIter(Node * head)
    {
    	  Node * root = NULL;
    	  
    	  while(head !=NULL)
          {
          	  Node * next = head -> next;
          	  head->next = root;
          	  root = head;
          	  head = next;
		  }
		  return root;
	}

2. Recursive Programme To reverse a Linked List :  Time O(n) + Space O(1)
    /*
        time : O(n)
        space : O(1)
        
    
    */ 
   Node *  reverseRec(Node * head)
   { 
      if(head == NULL || head->next == NULL )
      Node  * rest = reverseRec(head->next);
      head->next->next = head;
      head->next = NULL;
      
      return rest;
      
      
   }


3. Using Stack   O(n) + O(n)

   void Reverse(Node * head)
   {
   	   stack<Node*>s;
   	   
   	   Node * curr = *head;
   	   
   	   while(curr->next != NULL)
   	   {
   	   	   s.push(curr);
   	   	   curr = curr->next;
	   }
	   *head = curr;
	   
	   while(!s.empty())
	   {
	   	  curr->next = s.top();
	   	  s.pop();
	   	  curr = curr->next;
	   	  
	   }
	   curr->next = NULL;
	   
   }


4. Using Array 

   1)  count the number of nodes and then start storing the values of linked list in the array
   2)  print the array acc to need 
   












