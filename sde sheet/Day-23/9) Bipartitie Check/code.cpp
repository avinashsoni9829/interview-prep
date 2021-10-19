class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int> visited(size,0);
        vector<int> color(size,-1);
        for(int i=0;i<size;i++){
            if(!visited[i]){
                if(checkBipartite(i,visited,graph,color,-1)==false){ //the given graph is not bipartite
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipartite(int curr,vector<int>& visited,vector<vector<int>>& graph,vector<int>& color,int parent){
        visited[curr]=1;
        if(parent == -1){
            color[curr]=0;
        }
        else{
            color[curr]= (color[parent]==0) ? 1 : 0;
        }
        for(auto nbr:graph[curr]){
            if(!visited[nbr]){
                if(checkBipartite(nbr,visited,graph,color,curr)==false){
                    return false;
                }
            }
            else{
                if(nbr!=parent && color[nbr]==color[curr]){
                    return false;
                }
                    
            }
        }
        return true;
    
    }
};
