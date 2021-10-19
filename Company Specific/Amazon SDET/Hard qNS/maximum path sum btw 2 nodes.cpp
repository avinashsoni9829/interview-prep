class Solution {
public:
   
    int f(Node * root , int&ans){
          if(root == NULL) return 0;
          
          if(root -> left == NULL and root -> right == NULL){
               return root -> data;
          }
          
          int left = f(root -> left , ans);
          int right = f(root -> right , ans);
          
          
          if(root -> left and root -> right){
               
               ans = max(ans,left + right + root -> data);
               
               return max(left , right)  + root -> data;
               
               
          }
          
          if(root -> left == NULL) return right + root -> data;
          else
          {
               return left + root -> data;
          }
    }




    int maxPathSum(Node* root)
    {
         if(root == NULL) return 0 ;
         
         int ans = INT_MIN;
         
         int x = f(root , ans);
         
         if(ans == INT_MIN) return x;
         
         return ans;
    }
};
