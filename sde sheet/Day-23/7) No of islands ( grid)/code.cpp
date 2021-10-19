/*
   time : O(n)
   

*/


class Solution {
public:
    
      
     void dfs(vector<vector<char>>&grid,int x,int y,int r,int c ){
         
         // check :  out of bound ,  not visited and not 1
         
         if(x<0 or x>=r or y<0 or y>=c or grid[x][y]!='1'){
             return ;    
         }
         
         grid[x][y] ='2';
         
         // make recursive calls
         
         dfs(grid,x-1,y,r,c);  // T
         dfs(grid,x+1,y,r,c);  // D
         dfs(grid,x,y+1,r,c);  // R
         dfs(grid,x,y-1,r,c); //  l
         
     }
      
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        
        if(rows == 0) return 0;
        
        int ans = 0;
        
        for(int i = 0 ; i< rows ; ++i){
            for(int j = 0 ; j< cols ; ++j){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,rows,cols);
                    ans = ans + 1;
                }
            }
        }
        
        return ans;
        
        
    }
};
