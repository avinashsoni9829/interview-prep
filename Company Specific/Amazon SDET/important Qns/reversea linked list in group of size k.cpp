// reverse a linked list in group of size k 


node * reverseGroupK(node * head ,int k){
	   if(head  == NULL or k == 1) return head;
	   
	   node * dummy = new node(0);
	   
	   dummy -> next = head;
	   
	   node * curr = dummy;
	   
	   node * pre = dummy;
	   
	   node * nex = dummy;
	   
	   int len = length(head);
	   
	   
	   
	   while(len >= k){
	   	   
	   	   curr = pre -> next;
	   	   
	   	   nex = curr -> next;
	   	   
	   	   for(int i =  1 ; i < k ; ++i){
	   	   	   
	   	   	   
	   	   	   curr -> next = nex -> next;
	   	   	   
	   	   	   nex -> next = pre -> next;
	   	   	   
	   	   	   pre -> next = nex;
	   	   	   
	   	   	   nex = curr -> next;
	   	   	   
	   	  }
	   	  
	   	  pre = curr;
	   	  
	   	  len = len - k ;
	   	   
	   	   
	   	   
	   	   
	   	   
	   }
	   
	   return dummy -> next;
	   
	   
	   
	   
}
