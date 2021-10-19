

/*

       time : O( n * m )
       space : O(1)
       
*/


class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    
    bool safe(vector<vector<int>>&grid , int x , int y , vector<vector<bool>>&vis){
        
        
        int  n = grid.size();
        int  m = grid[0].size();
        
        return (x>=0 and x<n) and (y>=0 and y<m) and (grid[x][y] == 1) and (vis[x][y] == false);
    }
    
    
    
    
    void dfs(vector<vector<int>>&grid, int r , int c , vector<vector<bool>>&vis,int &cnt){
       
       
        static int dx[] = { -1 , -1 , -1 ,  0 , 0 , 1 , 1 , 1 };
        static int dy[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 ,  1 };
       
        
        vis[r][c] = true;
        
        
        for(int u =  0 ;  u  < 8 ; ++u){
                int xx =  r + dx[u];
                int yy =  c + dy[u];
                
                if(safe(grid, xx , yy , vis)){
                    
                    cnt = cnt + 1;
                    
                    dfs(grid , xx , yy , vis , cnt);
                    
                }
        }
        
        
    }
    
    
    
    
    
    int findMaxArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        vector< vector<bool> >vis(n ,vector<bool>(m , false));
        
        int ans = INT_MIN;
        
        for(int  i = 0 ; i < n ; ++i){
              for(int  j = 0 ; j < m ; ++j){
                    
                    if(grid[i][j] == 1 and vis[i][j] == false){
                     
                     int cnt  = 1 ;
                     
                     dfs(grid , i , j , vis,cnt);
                     
                     ans = max(ans,cnt);
                          
                          
                    }
              }
        }
        
        
        return ans;
        
    }
};
