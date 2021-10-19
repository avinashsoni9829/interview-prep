class Solution {
  public:
  
  
  int bfs2(map<Node * , Node * >&mp , Node * src){
        
        queue<Node *> q;
        q.push(src);
        
        map<Node * ,bool>vis;
        vis[src] = true;
        int ans  = 0 ;
        
        while(!q.empty()){
              
              int sz = q.size();
              int ct = 0;
              
              for(int  i = 0 ; i <  sz ; ++i){
                    Node * curr = q.front();
                    
                    q.pop();
                    
                    if(curr -> left and !vis[curr -> left]){
                          ct = 1;
                          vis[curr -> left] = true;
                          q.push(curr -> left);
                          
                          
                    }
                    
                    if(curr -> right and !vis[curr -> right]){
                          ct = 1;
                          vis[curr -> right] = true;
                          q.push(curr -> right);
                          
                    }
                    
                    if(mp[curr] and !vis[mp[curr]]){
                         ct = 1;
                         vis[mp[curr]] = true;
                         q.push(mp[curr]);
                         
                    }
                    
                    
              }
              
              if(ct) ans = ans + 1;
              
        }
        
        return ans;
        
  }
    
  
  
  
  
  
  
  
  
  Node * bfs1(Node * root , map<Node * , Node *>&mp , int target){
         
         queue<Node *>q;
         q.push(root);
         Node * tnode = NULL;
         while(!q.empty()){
               Node * curr = q.front();
               q.pop();
               if(curr -> data == target and tnode == NULL){
                    tnode = curr;
               }
               if(curr -> left){
                    mp[curr -> left] = curr;
                    q.push(curr -> left);
               }
               if(curr -> right){
                     mp[curr -> right] = curr;
                     q.push(curr -> right);
               }
         }
         
         return tnode;
         
  }
  
  
  
  
  
  
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>mp;
        Node * firepoint = bfs1(root , mp , target);
        int ans = bfs2(mp,firepoint);
        
        return ans;
    }
};

