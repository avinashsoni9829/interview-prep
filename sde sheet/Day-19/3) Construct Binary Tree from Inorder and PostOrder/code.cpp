Node * helper(int in[] , int post[] , int low , int high , int &idx , unordered_map<int,int>&mp){
        if(low > high){
             return NULL;
        }
        
        Node * curr = new Node(post[idx]);
        
        idx = idx - 1;
        
        if(low == high)  return curr;
         
        int pos = mp[curr->data];
        
        // first populate right here 
        curr -> right = helper(in,post,pos + 1 ,high,idx,mp);
        
        curr -> left  = helper(in,post,low,pos - 1,idx,mp);
        
        
        return curr;
}


Node *buildTree(int in[], int post[], int n) {

    unordered_map<int,int>mp;
    int idx = n - 1;
    
    /* storing the values in the map */
    
    for(int i = 0  ; i < n  ; ++i){
         mp[in[i]] = i ;
    }
    
    Node * ans = helper(in,post,0,n-1,idx,mp);
     
     return ans;
     

}

