class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
  	    vector<int>ans;
  	    queue<int>q;
  	    q.push(0);
  	    
  	    vector<int>vis(V,0);
  	    vis[0] = 1;
  	    
  	    
  	    while(!q.empty()){
  	          int f = q.front();
  	          q.pop();
  	          
  	          ans.push_back(f);
  	          
  	          for(auto child : adj[f]){
  	              if(!vis[child]){
  	                  vis[child] = 1;
  	                  q.push(child);
  	                  
  	              }
  	          }
  	    }
	    
	    return ans;
	    
	}
};
