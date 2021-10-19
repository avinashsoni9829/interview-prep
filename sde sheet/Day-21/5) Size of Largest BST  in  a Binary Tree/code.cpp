
vector<int> helper(Node * root){
    // isBst ,  size , min , max
    
      if(!root){
          return { 1 ,0,INT_MAX,INT_MIN};
         }
         
         if(!root->left and !root->right){
             return {1,1,root->data,root->data};
         }
         
         
         vector<int> l = helper(root->left);
         vector<int> r = helper(root->right);
         
         // if both the child are having BST prop
         
         if(l[0] and r[0]){
               // if root is b/w the max and min
               // i,e root->data is greater than the maximum at left
               // and root->data is less than the minimum at right 
               
               
               if(root->data >l[3] and root->data < r[2]){
                  int x = l[2];
                  int y = r[3];
                  
                  if(x==INT_MAX) x = root -> data;
                  if(y==INT_MIN) y = root -> data;
                  
                  return {1 , l[1] + r[1] + 1 , x , y};
                    
               }
               
         }
         
         return {0,max(l[1],r[1]),0,0};
         
         
}




int largestBst(Node *root)
{
	vector<int>ans = helper(root);
	return ans[1];
	
}
