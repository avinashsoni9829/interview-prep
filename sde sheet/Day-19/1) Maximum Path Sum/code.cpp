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
    
    
    	int helper(TreeNode * root,int &ans)
		{
        
        if(!root) return 0 ;
        int left  =  helper(root->left,ans);
        int right =  helper(root->right,ans);
        
        int mx1 = max(max(left,right)+root->val ,root->val);
        int mx2 = max(mx1,left+right+root->val);
        ans = max(mx2,ans);
        
        return mx1;
        
        }
    int maxPathSum(TreeNode* root) 
	{
        
        if(root == NULL) return 0 ;
        int ans = INT_MIN;
        helper(root,ans);
        return ans;
	}
};  
