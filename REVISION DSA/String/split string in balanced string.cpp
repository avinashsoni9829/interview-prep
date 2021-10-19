class Solution {
public:

    
    
    int balancedStringSplit(string s) {
        
        int n = s.length();
        
        int curr_L = 0 , curr_R = 0 ;
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; ++i){
               if(curr_L == curr_R and curr_L!=0){
                   
                   
                     curr_L = 0;
                     curr_R = 0;
                     ans = ans + 1;
               }
              
            curr_L = curr_L + (s[i] == 'L');
            
            curr_R = curr_R + (s[i] == 'R');
             
          
            
        }
        
         if(curr_L == curr_R and curr_L!=0){
                     curr_L = 0;
                     curr_R = 0;
                     ans = ans + 1;
         }
        
        
        return ans;
        
        
    }
};
