class Solution {
public:
    #define debug(a) cout << #a << "=" << a << ' '<<endl;
     int bs(vector<int>a,int low,int high)
     {
          int idx = -1 ;
          
          while(low<=high)
          { 
             int mid = (low + high)/2;
             if(a[mid] < 0)
             {
                 idx = mid;
                 high = mid - 1;
             }
             else
             {
                 low = mid + 1;
             }
          }
         
         return idx;
         
     }
    
    
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
                    if(bs(grid[row_pointer],0,m-1)!=-1)
                   col_pointer = bs(grid[row_pointer],0,m-1);
                   else
                      col_pointer = col_pointer + 1;
                  
              }
             
               
         }
         
         return neg_count;
         
         
        
      
    }
};