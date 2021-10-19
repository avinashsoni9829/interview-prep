/*  
     time : O(n)
     space  : O(1)
     
     

*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n = s.length();
        
        int curr_len = 1 , prev_len = 0 ;
        int ans = 0 ;
        for(int  i =  1; i < n ;++i){
             if(s[i]!=s[i-1]){
                 ans = ans + min(curr_len,prev_len);
                 prev_len = curr_len;
                 curr_len = 1;
             }
             else
             {
                  curr_len = curr_len + 1;
             }
        }
        
        ans = ans + min(curr_len ,prev_len);
        
        return ans;
        
        
    }
};
