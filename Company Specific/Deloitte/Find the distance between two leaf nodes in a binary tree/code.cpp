class Solution{
    public:
    
	
	
	
	Node * lca(Node * root,int a , int b){
         if(!root) return root;
         
         if(root -> data == a or root ->data == b) return root;
         
         Node * l = lca(root -> left , a , b);
         
         Node * r = lca(root -> right , a , b);
         
         if(l and r) return root;
         if(l) return l;
         return r;
         
    }
    
    
    
    
    
    
    int solve(Node * root , int v){
         if(!root) return  0 ;
         if(root -> data == v   ) return 1;
         int l = solve(root -> left , v);
         int r = solve(root -> right , v);
         
         if(!l and !r ) return 0;
         
         return  l + r + 1;
    }
    
    
    
    int findDist(Node* root, int a, int b) {
       
        Node * LCA = lca(root , a , b);
        int x = solve(LCA , a);
        int y = solve(LCA , b);
        
        return x + y - 2;    
    }
};
