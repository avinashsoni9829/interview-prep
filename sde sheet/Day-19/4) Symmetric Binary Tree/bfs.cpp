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
     bool isSymmetric(TreeNode* root) {
        if(root==NULL){return true;}
  
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            auto leftchild = q.front();
            q.pop();
            auto rightchild = q.front();
            q.pop();
            if(leftchild==NULL && rightchild == NULL){
                continue;
            }
            if(leftchild==NULL || rightchild == NULL){
                return false;
            }
            if(leftchild->val!=rightchild->val){return false;}
            q.push(leftchild->left);
            q.push(rightchild->right);
            q.push(leftchild->right);
            q.push(rightchild->left);
            
        }
    return true;
    }
};
