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
    
    void dfs(TreeNode * root, vector<vector<int>>&ans , int level){
        
        if(level ==  ans.size()) ans.push_back({});
        ans[level].insert(level%2!=0 ? ans[level].begin() : ans[level].end()  ,root->val);
        
        if(root->left) dfs(root->left,ans,level+1);
        if(root->right) dfs(root->right,ans,level+1);
        
    }
    
    
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
        if(!root) return ans;
        
        dfs(root,ans,0);
        return ans;
        
        
        
    }
};
