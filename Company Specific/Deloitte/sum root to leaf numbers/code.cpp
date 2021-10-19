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
    int ans ;
    
    void helper(TreeNode * root ,   int curr_sum ){
         
          if(root == NULL) return ;
        
          curr_sum = curr_sum * 10 + root -> val;
        
          if(root -> left == NULL and root -> right == NULL){
               ans = ans + curr_sum;
              return;
          }
          
          helper(root -> left ,curr_sum);
          helper(root -> right, curr_sum);
        
        
          
    }
    
    
    int sumNumbers(TreeNode* root) {
       ans = 0 ;
       helper(root , 0);
       return ans;
        
        
    }
};
