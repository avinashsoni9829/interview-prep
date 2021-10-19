
/*
   time : O(log(min(n,m))
   
   
   
   

*/


class Solution {
public:
    
    
    double solve(vector<int>&a, vector<int>&b){
          int m = a.size();
          int n = b.size();
        
          if(m>n) return solve(b,a);  // n should be greaterr 
        
          int low = 0 ,  high = m;
        
          while(low <= high){
              
               int i1 = low + (high - low ) /2 ;
               
               int i2 = ( n + m + 1)/2 - i1;
              
              
               int max1 = (i1 == 0) ? INT_MIN : a[i1-1];
               int min1 = (i1 == m) ? INT_MAX : a[i1];
              
               int max2 = (i2 == 0) ? INT_MIN : b[i2 - 1];
               int min2 = (i2 == n) ? INT_MAX : b[i2];
                   
                   
               if(max1 <=min2 and max2 <= min1){
                    if((n+m)%2 == 0){
                         return (double) (max(max1,max2) + min(min1,min2))/2;
                        
                    }
                    else
                    {
                         return (double)(max(max1,max2));
                    }
               }
               else
                    if(max1 > min2){
                         high = i1 - 1;
                    }
                    else{
                         low = i1 + 1;
                    }
          }
        
        return -1.0;
        
    }
    
    
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        return solve(nums1,nums2);
        
    }
};
