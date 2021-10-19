//  normal bst to balanced bst
void reorderList(Node* head) {
    
    if(!head  or !head -> next)  return;
    // find the middle
    Node * slow = head , * fast = head;
    
    
    while(fast and fast -> next){
          slow = slow -> next;
          fast = fast -> next -> next;
    }
    
    Node * prev = NULL , *curr = slow , *tmp;
    
    while(curr){
          tmp = curr -> next;
          curr -> next = prev ;
          prev = curr;
          curr = tmp;
    }
    
    
    Node * n1 = head , *n2 = prev;
    
    while(n2 -> next){
          tmp = n1 -> next;
          n1 -> next = n2;
          n1 = tmp;
          
          tmp = n2 -> next;
          n2 -> next = n1;
          n2 = tmp;
          
    }
    
    
    
    
}
