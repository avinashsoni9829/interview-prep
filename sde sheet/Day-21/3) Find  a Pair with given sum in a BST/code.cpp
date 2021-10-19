class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    
    void populateinorder(Node * root,int v,vector<int>&inorder){
          
          if(!root) return;
          
          populateinorder(root->left,v,inorder);
          inorder.push_back(root->data);
          populateinorder(root->right,v,inorder);
    }
    
    
    int isPairPresent(struct Node *root, int target)
    {
        vector<int>inorder;
         
        populateinorder(root,target,inorder);
        
        int n = inorder.size();
        bool ans = 0;
        
        int low = 0 , high =  n - 1;
        
        while(low<high){
               if(inorder[low] + inorder[high] == target){
                    ans  = 1;
                    break;
               }
               else
               if(inorder[low] + inorder[high] < target){
                     low = low + 1;
               }
               else
               {
                    high = high - 1;
               }
        }
        
        return ans;
        
        
    }
};
