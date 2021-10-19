class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool dfs(int src , int par , vector<int>adj[] ,vector<bool>&vis){
          
           vis[src] = true;
           
            for(auto child : adj[src]){
                  if(!vis[child]){
                        
                        bool flag = dfs(child , src , adj , vis);
                        if(flag) return true;
                  }
                  else
                     if(child!=par and vis[child] == true){
                          return true;
                          
                     }
            }
            
            return false;
            	
            
            
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool>vis(V , false);
	    
	    for(int  i = 0 ; i <  V ; ++i){
	        
	        if(!vis[i]){
	            bool flag = dfs(i , -1 , adj , vis);
	            if(flag) return true;   
	        }
	    }
	    
	    return false;
	    
	}
};
