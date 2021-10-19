class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>mp;
        
        queue<pair<Node * ,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
               Node * curr = q.front().first;
               int h = q.front().second;
               
               q.pop();
               
               mp[h] = curr->data;
               
               if(curr->left) q.push({curr->left,h-1});
               
               if(curr->right) q.push({curr->right,h+1});
               
               
        }
        
        for(auto z:mp){
            ans.push_back(z.second);
        }
        
        return ans;
        
    }
};
