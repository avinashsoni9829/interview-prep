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
 
 time : O(logn)
 space : O(1)
 
 */
class Solution {
public:
    
    void helper(TreeNode * root,int k , int &counter , int &ans){
          if(!root) return;
          
          //  inorder  Left work Right
        
          helper(root->left,k,counter,ans);
          
           if(counter == k-1){
             ans = root->val;
               counter = counter + 1;
               return;
           }
           else{
              counter = counter + 1;   
           }
        
        helper(root->right,k,counter,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = -1;
        int counter = 0 ;
        helper(root,k,counter,ans);
        
        return ans;
        
        
    }
};

/*  --------------------------------  Kth Largest ----------------------------------------- */


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
 
 time : O(k)
 space : O(1)
 
 */
class Solution {
public:
    
    void helper(TreeNode * root,int k , int &counter , int &ans){
          if(!root) return;
          
          //  reverse  inorder  right work left
        helper(root->right,k,counter,ans);
          
          
           if(counter == k-1){
             ans = root->val;
               counter = counter + 1;
               return;
           }
           else{
              counter = counter + 1;   
           }
        
        helper(root->left,k,counter,ans);
    }
    
    int kthLargest(TreeNode* root, int k) {
        
        int ans = -1;
        int counter = 0 ;
        helper(root,k,counter,ans);
        
        return ans;
        
        
    }
};
