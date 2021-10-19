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


    time : O (n)
    space : O(n)
    
    BFS solution
    
*/

class Solution {
public:
    Node* connect(Node* root) {
   
         if(!root) return root;
        
        
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty()){
              
            int sz = q.size();
            vector<Node*>nodes;
            for(int  i= 0 ; i < sz;++i){
                
                Node * curr = q.front();
                q.pop();
                
                nodes.push_back(curr);
                
                if(curr->left) q.push(curr->left);
                
                if(curr->right) q.push(curr->right);
                
            }
            
            int x = nodes.size();
            
            for(int  i = 0 ; i < x - 1 ; ++i){
                  
                nodes[i] -> next = nodes[i+1];
                
            }
            
            nodes[x-1]->next = NULL;
               
        }
        
        return root;
        
    }
};
