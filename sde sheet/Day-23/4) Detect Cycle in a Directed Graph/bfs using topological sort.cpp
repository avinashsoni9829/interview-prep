class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	  vector<int>topological_sort;
	   	  
	   	  vector<int>indegree(V,0);
	   	  
	   	  queue<int>q;
	   	  
	   	  for(int i = 0 ; i < V ; ++i){
	   	       for(auto child : adj[i]){
	   	            indegree[child] = indegree[child] + 1;
	   	       }
	   	  }
	   	  
	   	  
	   	  for(int  i = 0 ; i < V ; ++i){
	   	        if(indegree[i] == 0)
				{
	   	             q.push(i);
	   	        }
	   	  }
	   	  
	   	  
	   	  while(!q.empty()){
	   	      
	   	      int top  = q.front();
	   	      q.pop();
	   	      
	   	      topological_sort.push_back(top);
	   	      
	   	      for(auto child : adj[top]){
	   	          
	   	           indegree[child] = indegree[child] - 1;
	   	           
	   	           if(indegree[child] == 0) q.push(child);
	   	      }
	   	      
	   	      
	   	  }
	   	  
	   	  
	   	  int sz = topological_sort.size();
	   	  
	   	  if(sz!=V) return true;
	   	  
	   	  return false;
	   	  
	   	  
	   	  
	   	  
	}
};
