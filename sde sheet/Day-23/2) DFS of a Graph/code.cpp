class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsview;
    
    void dfs(int src,vector<int>&vis,vector<int>graph[]){
        // 1 . mark the src node as visited
        vis[src] = true;
        dfsview.push_back(src);
        // 2. check the adjaceney list of the src node and visited it 
        for(auto child : graph[src]){
            
            // 3 . if the child is not visited then start DFS call on the child
            
            if(!vis[child]){
                  dfs(child,vis,graph);
            }
            
        }
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    dfsview.clear();
	    
	    vector<int>vis(V,0);
	    
	    dfs(0,vis,adj);
	    
	    return dfsview;
	    
	}
};
