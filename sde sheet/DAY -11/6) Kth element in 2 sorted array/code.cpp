
/*

    time : O( log ( min ( n , m ) ) 
    space : O(1)
    
*/

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
           // m should be higher as we want to do bs on minimum size
            if(n>m){
                 return kthElement(arr2,arr1,m,n,k);
            }
            
            int low = max(0 , k - m );
            
            int high = min(k,n);
            
            
            while(low <=high){
                
                int i1 = low + (high - low) / 2 ;
                int i2 = k - i1;
                
                int l1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
                int l2 = (i2 == 0) ? INT_MIN : arr2[i2 -1];
                
                int r1 = (i1 == n) ? INT_MAX : arr1[i1];
                int r2 = (i2 == m) ? INT_MAX : arr2[i2];
                
                
                if(l1 <= r2 and l2 <=r1){
                     return max(l1,l2);
                }
                else
                  if(l1 > l2){
                       high = i1 - 1;
                  }
                  else
                  {
                       low = i1 + 1;
                  }
                
            }  
            
            return   -1;
            
        
    }
};
