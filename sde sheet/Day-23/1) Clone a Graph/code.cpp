/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

   time : O( E * V)
   E = Edge'
   V = Vertices
   
*/

void dfs(Node * curr,Node * node ,vector<Node*>&vis){
 
     vis[node->val] = node;
    
    for(auto child : curr->neighbors){
        
        if(!vis[child->val]){
            Node * newNode = new Node(child ->val);
            node->neighbors.push_back(newNode);
            dfs(child,newNode,vis);
        }
        else
        {
            (node -> neighbors).push_back(vis[child->val]);
        }
    }
  
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL){
                return NULL;
        }
        
        vector<Node *> vis(1000,NULL);
        Node * copy = new Node(node->val);
        
        vis[node->val] = copy;
        
        for(auto curr : node->neighbors){
            // if not visited then create a new node
            if(vis[curr->val] == NULL){
                Node * newNode = new Node(curr->val);
                // add the node to the clone
                copy->neighbors.push_back(newNode);
                
                dfs(curr,newNode,vis);
                
            }
            else
            {
                 copy->neighbors.push_back(vis[curr->val]);
                
            }
        }
        
        return copy;
        
    }
};
