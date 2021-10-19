class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
       
       int ans = 0 ; 
       if(!node) ans;
       
       queue<Node*>q;
       q.push(node);
       
       while(!q.empty()){
            int sz = q.size();
            for(int  i = 0  ;i < sz ;++i){
                
        
            Node * curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right)q.push(curr->right);
              
            }
            
            ans = ans + 1;
            
           
       }
       
       return ans;
       
        
        
    }
};
