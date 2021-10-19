Linked List Insertion 

Insert at front


void insertfront(Node**head , int data)
{
	  
	  Node * new_node = new Node();
	  
	  new_node -> data = data ;
	  
	  new_node -> next = *head;
	  
	  *head = new_node;
}

Insert after a linkedList 

void insertafter(Node * prev , int data)
{
     if(prev == NULL){
     	return ;
	 }	
	
	 Node * new_node = new Node();
	 
	 new_node -> data = data;
	 
	 new_node -> next = prev -> next;
	 
	 prev -> next = new_node;
}

Insert at end

void insertend(Node ** head , int data)
{
	  
	  Node * curl =  *head ;
	  Node * new_node = new Node();
	  if(*head == NULL){
	  	 *head = new_node ;
	  	 return ;
	  }
	  
	  new_node -> data = data;
	  new_node -> next = NULL;
	  
	  while(curl!=NULL){
	  	curl = curl -> next;
	  }
	  
	  curl -> next = new_node;
	  
	  
}


