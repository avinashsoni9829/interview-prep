/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        // find the depth upto first leaf node 
        if(root == NULL) return 0 ;
        
        queue<TreeNode *>q;
        q.push(root);
        
        int ans = 1;
        
        while(!q.empty()){
            
              int size = q.size();
            
            for(int i = 0 ; i < size ; ++i){
              TreeNode * curr = q.front();
              q.pop();
            
              if(curr -> left == NULL and curr -> right == NULL){
                  return ans;
              }
                
              if(curr -> left) q.push(curr -> left);
              if(curr -> right) q.push(curr -> right);
                
                
            }
            
            ans = ans + 1;
                  
        }
        
        return ans;
        
    }
};
