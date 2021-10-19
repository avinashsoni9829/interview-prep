class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // storing the indegree 
	    vector<int>indegree(V , 0 );
	    vector<int>ans;
	    
	    // queue for maintaing all the nodes with indegree  = 0 
	    queue<int>q;
	    
	    // calculating the indegree of each node 
	    
	    for(int i = 0 ;  i < V ; ++i){
	         for(auto  child  : adj[i]){
	              indegree[child] = indegree[child] +  1 ;
	         }
	    }
	    
	    // putting the nodes with indegree  = 0  in the queue 
	    
	    for(int i = 0 ; i < V ; ++i){
	         if(indegree[i] == 0){
	              q.push(i);
	         }
	    }
	    
	    while(!q.empty()){
	          int top = q.front();
	          q.pop();
	          
	          ans.push_back(top);
	          
	          
	          for(auto child : adj[top]){
	               
	               indegree[child] = indegree[child] - 1;
	               
	               if(indegree[child] == 0){
	                    q.push(child);
	                    
	               }
	          }
	    }
	    
	    return ans;
	    
	    
	}
};
