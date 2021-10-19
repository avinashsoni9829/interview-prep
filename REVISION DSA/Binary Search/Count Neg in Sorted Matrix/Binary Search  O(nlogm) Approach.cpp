// Count Negative Numbers in a Sorted Matrix 
class Solution {
public:
    
    
    int bs(vector<int>a,int n,int m)
    {
       int low = 0 ;
       int high  = m - 1 ;
        
       int res = m;
       
       while(low<=high)
       {
          int mid = (low + high) / 2;
          
          if(a[mid]<0)
          {
             res = mid;
             high = mid-1;
          }
          else
          {
               low = mid+1;
          }
       }
        
       return (m-res);
        
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        
          int  n = grid.size();
          int  m = grid[0].size();
          
          int ans = 0 ;
        
            for(int i = 0  ; i < n ;++i)
            {
             ans = ans + bs(grid[i],n,m);   
            }
        
            return ans;
        
        
      
    }
};