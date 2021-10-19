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
 
 
  time : O(n)
  
  space : O(n)
  
 */
class Solution {
public:
    
    unordered_map<int,int>mp;
    int idx = 0;
    
   TreeNode* helper(vector<int>&pre,vector<int>&in,int low,int high){
        
        if(low > high) return NULL;
        
        TreeNode * preNode = new TreeNode(pre[idx++]);
        
        
        if(low == high) return preNode;
        
        int pos = mp[preNode -> val];
        
        preNode->left = helper(pre,in,low,pos-1);
       
        preNode -> right = helper(pre,in,pos + 1,high);
        
        return preNode;
       
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        idx = 0;
        mp.clear();
        
        int n = inorder.size();
        
        for(int i = 0 ; i<n;++i){
        mp[inorder[i]] = i;    
        }
        
        TreeNode *  ans = helper(preorder,inorder,0,n-1);
        
        return ans;
        
        
    }
};
