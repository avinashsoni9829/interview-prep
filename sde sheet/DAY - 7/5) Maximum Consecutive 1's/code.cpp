// kadanes algo 
/* 

   time : O(n)
   space : O(1)
   

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        
        int curr=  0 ;
        int overall = 0 ;
        int n = a.size();
        for(int i = 0 ; i < n ; ++i)
        {
           if(a[i]== 1) 
           {
             curr = curr + 1;   
           }
           else
           {
              overall = max(curr,overall);
               curr = 0 ;
             
           }
            
        }
        
        overall = max(curr,overall);
        
        return overall;
        
        
        
    }
};
