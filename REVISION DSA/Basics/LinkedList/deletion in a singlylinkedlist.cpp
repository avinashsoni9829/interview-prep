Delete a node in a linkedlist 

void deleteNode(Node ** head , int key){
	  
	  Node * curr = * head , *prev ;
	  
	  // if head node is to be deleted 
	  
	  if(curr!=NULL and curr -> data == key){
	  	    *head = curr -> next ;
	  	    delete(curr);
	  	    return;
     }
     
     // finding the first occurance of the linked list node
     
     while(curr!=NULL and curr -> data != key){
     	
     	prev = curr;
     	curr = curr -> next;
    }
    // if no key value occurs 
    if(curr == NULL){
    	 return ;
	}
	
	prev -> next =  curr -> next;
	
	delete(curr);
	
}



// Recursive solution 


void deleteNoderecur(Node ** head , int key){
	  if(*head == NULL){
	  	return;
	  }
	  if(*head -> data == key){
	  	  Node * temp = *head ;
	  	  delete(temp);
	  	  head = head -> next;
	  	  return;
	  }
	  
   deleteNoderecur(head -> next , key);
   	  
	  
}







