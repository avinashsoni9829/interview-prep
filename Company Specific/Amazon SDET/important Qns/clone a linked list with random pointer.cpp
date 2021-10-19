//clone a linked list with random pointer 

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        Node * curr  = head;
        
        Node * temp ;
        // A ->  a -> B ->  b ->  C ->  c ->  D ->  d -> NULL
        
        while(curr){
               temp = curr -> next;
               curr -> next = new Node(curr -> data);
               curr -> next -> next = temp;
               curr = temp;
        }
        
        //restore 
        curr = head;
        
        while(curr){
               curr -> next -> arb = curr -> arb ? curr -> arb -> next : curr -> arb;
               
               curr = curr -> next -> next;
        }
        
        // removing clone and original 
        
        
        Node * original = head;
        Node * copy     = head -> next;
        temp = copy;
        
        while(original  and copy){
               original -> next = original -> next -> next;
               
               copy -> next = copy -> next ? copy -> next -> next : copy -> next;
               
               original = original -> next;
               
               copy = copy -> next;
               
        }
        
        
        return temp;
         
        
        
    }

};

