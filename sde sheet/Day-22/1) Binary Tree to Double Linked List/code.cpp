
// time : O(n) space :O(1)



class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void helper(Node * root , Node* &head , Node* &prev){
        if(root == NULL) return;
        
        
        helper(root -> left ,head,prev);
        root -> left = prev;
        if(prev == NULL){
             head = root;
        }
        else
        {
             
             prev -> right = root;
        }
        
        prev = root;
        
        helper(root ->right , head,prev);
        
    }
    
    Node * bToDLL(Node *root)
    {
       Node * head = NULL;
       Node * prev = NULL;
       helper(root,head,prev);
       return head;
    }
};
