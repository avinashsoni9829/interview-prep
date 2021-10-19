class Solution {
public:
     int countNegatives(vector<vector<int>>& grid) {
        
         // pruning approach  O(m + n) solution
         
         int n = grid.size();
         
         int m = grid[0].size();
         
         if(n==0) return  0 ;
         
         int row_pointer = n-1;
         int col_pointer = 0;
         int neg_count  = 0;
         
         while(row_pointer>=0 and col_pointer<m)
         {
             
              if(grid[row_pointer][col_pointer]<0)
              {
                   row_pointer = row_pointer - 1;
                   
                   neg_count = neg_count + m - col_pointer;
                  
              }
              else
              {
                   col_pointer = col_pointer + 1; 
              }
             
               
         }
         
         return neg_count;
         
         
        
      
    }
};