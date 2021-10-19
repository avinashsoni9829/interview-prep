/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 
 time : O(n)
 
 */
class Solution {
public:
    
    bool pathfind(TreeNode * root,TreeNode * curr,vector<TreeNode*>&a){
      
         if(root == NULL){
             return false;
         }
        
        if(root -> val == curr -> val){
            a.push_back(root );
            return true;
        }
        
        bool left = pathfind(root->left,curr,a);
       if(left){
           a.push_back(root);
           
           
            return true;
       }
        
        bool right = pathfind(root->right,curr,a);
        
        if(right){
        a.push_back(root);
            
            return true;
        }
        
        
        return false;
        
        
        
    
    
    }
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        if(!root) return root;
        
        vector<TreeNode*>path1,path2;
        
        
        pathfind(root,p,path1);
        pathfind(root,q,path2);
        
        
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        
       TreeNode * ans;
        
        int  n = path1.size();
        int  m = path2.size();
        
        int i = 0 ;
        
        while( i < n and i < m){
             if(path1[i] -> val !=path2[i]->val){
                 break;
             }
            else
            {
                 ans = path1[i];
            }
            
            i = i + 1;
            
        }
        
        return ans;
        
    }
};
