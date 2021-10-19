class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
	
	bool dfs(int src , vector<bool>&vis , vector<bool>&order , vector<int>adj[]){
	    
	     vis[src] = true;
	     order[src] = true;
	     
	     for(auto  child : adj[src]){
	           
	           if(!vis[child]){
	                 bool flag  = dfs(child , vis, order, adj);
	                 
	                 if(flag) return true;
	           }
	           else
	           if(vis[child] == true and order[child] == true){
	                return true;
	           }
	     }
	     
	     order[src] = false;
	     
	     return false;
	     
	}
	
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   vector<bool>vis(V,false);
	   vector<bool>order(V,false);
	   
	   for(int i = 0 ; i < V ; ++i){
	        if(!vis[i]){
	              bool flag = dfs(i , vis , order , adj);
	              
	              if(flag) return true;
	        }
	   }
	   
	   return false;
	}
	
};
