class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        stack<TreeNode*>curr_stack;
        stack<TreeNode*>ans;
        
        curr_stack.push(root);
        
        while(!curr_stack.empty()){
             
               TreeNode * top = curr_stack.top();
               ans.push(top);
               
               curr_stack.pop();
            
               if(top -> left) curr_stack.push(top -> left);
               if(top -> right) curr_stack.push(top -> right);
               
               
             
         }
        
         while(!ans.empty()){
               TreeNode * temp = ans.top();
                ans.pop();
                res.push_back(temp -> val);
         }
        
        return res;
        
    } 
};
