class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root -> right);
        
        if(minLeft == 0 or minRight == 0){
             return  1 + max(minLeft , minRight);
        }
        
        return 1 + min(minLeft , minRight);
        
        
        
    }
};
