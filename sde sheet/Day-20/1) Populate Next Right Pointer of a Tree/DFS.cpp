/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void helper(Node * head){
        
        Node  * curr = head;
        
        while(curr!=NULL){
             curr -> left -> next = curr -> right;
             if(curr -> next != NULL){
                 
                 curr -> right -> next = curr -> next -> left;
               }
            curr = curr -> next;
            
        }
        
    }
    
    
    Node* connect(Node* root) {
       if(!root) return root;
          Node * leftnode = root;
        
        while(leftnode!=NULL and leftnode->left!=NULL)
        {
             helper(leftnode);
             leftnode = leftnode ->left;
        }
        
        return root;
    }
};
