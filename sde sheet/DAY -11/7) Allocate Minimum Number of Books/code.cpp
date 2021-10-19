class Solution 
{
    public:
    
    
    bool check(int a[] , int n , int m , int v){
          
          int students = 1 ; 
          
          int sum = 0  ;
          
          for(int i = 0 ; i <  n ; ++i){
                
                if(a[i] > v){
                     return false;
                }
                
                if(sum + a[i] > v){
                      students = students + 1;
                      sum = a[i];
                      
                      if(students > m){
                           return false;
                      }
                }
                else
                {
                     sum = sum  + a[i];
                }
                      
           }
           
           return true;
           
          
        
        
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        // binary search the ans concept
        
        if(n < m ) return -1;
        
        long long int sum = 0;
        
        for(int  i = 0 ;  i < n ; ++i){
               sum =  sum + a[i];
               
        }
        
        long long int low = 0 , high = sum;
        
        int ans = INT_MAX;
        
        
        while(low <= high){
               long long int mid = low + (high - low) / 2;
               
               if(check(a, n , m , mid)){
                     
                     ans = mid;
                     high = mid - 1;
               }
               else
               {
                    low = mid + 1;
               }
        }
        
        return ans;
        
    }
};
