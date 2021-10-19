class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
       map<int,int>mp;
       
      queue<pair<Node * ,int>>q;
      
      q.push({root,0});
      
      while(!q.empty()){
             Node * tp = q.front().first;
             int h = q.front().second;
             
             q.pop();
             
             if(!mp[h]) mp[h] = tp->data;
             if(tp->left) q.push({tp->left,h-1});
             if(tp->right)q.push({tp->right,h+1});
             
             
      }
      
      for(auto z:mp){
            ans.push_back(z.second);
            
      }
      
    
      return ans;
      
    }

};
