/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    
    bool pathfinder(TreeNode *root , int val , vector<TreeNode*>&a)
    {
         if(root == NULL) return true;
        
          if(root -> val == val){
                a.push_back(root);
                return true;
          }
        
          if(root -> val > val){
                bool left = pathfinder(root -> left , val , a);
                if(left){
                      a.push_back(root);
                      return true;
                }
          }
        
        
          if(root->val < val){
                bool right = pathfinder(root->right,val,a);
                 
                if(right){
                      a.push_back(root);
                      return true;
                }
          }
        
        
        return false;
        
     
    }
    
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
      vector<TreeNode*>path1 ,path2;
      pathfinder(root,p->val,path1);
        pathfinder(root,q->val,path2);
         
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        
        int  idx = 0 ;
        int  n = path1.size();
        int  m = path2.size();
        
        //for(auto z:path1) cout<<z -> val <<" "; cout<<endl;
        //for(auto z:path2) cout<<z -> val <<" "; cout<<endl;
        TreeNode  * ans = root;
        
        while(idx < n and idx < m ){
            
              if(path1[idx]->val == path2[idx] -> val){
                 // cout<<path1[idx] -> val<<endl;
                  ans = path1[idx];
                  idx = idx + 1;        
              }
              else 
              { 
                    
                    return ans;
              }
        }
        
        return ans;
        
    }
                
                
};
