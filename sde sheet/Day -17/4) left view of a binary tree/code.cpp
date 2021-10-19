/* Left view of a binary tree */

time : O(n)

Recursive Solution : 

 void helper(Node *  root , vector<int>&ans,int level,int *mxlevel){
       if(root == NULL){
              return ;
       }
       
       if(level > *mxlevel){
             ans.push_back(root -> data);
             *mxlevel = level;
       }
       
       helper(root->left,ans,level+1,mxlevel);
       helper(root->right,ans,level+1,mxlevel);
       
       
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int>ans;
   int mxlevel = 0 ;
   helper(root,ans,1,&mxlevel);
   return ans;
   
}



/* Level order traversal solution */

time : O(n)

vector<int> leftView(Node *root)
{
    
    
   vector<int>ans;
    if(root == NULL) return ans;
    
    queue<Node * > q;
    q.push(root);
    
    while(!q.empty()){
         int sz = q.size();
         
         for(int  i = 0 ; i < sz;++i){
         
                 
              Node * curr = q.front();
              q.pop();
              if(i==0)
              ans.push_back(curr->data);
              
              if(curr->left) q.push(curr->left);
              if(curr->right) q.push(curr->right);
         }
     
         
         
    }
    
    return ans;
}
