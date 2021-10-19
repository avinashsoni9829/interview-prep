time : O(n)
space: O(1)

class Solution {
public:
    string countAndSay(int n) {
        
        string start = "1";
        
        for(int i = 2; i<=n;++i){
            
            int cnt = 1;
            
            int d = start.length();
            string next;
            for(int  u = 0 ; u < d; ++u){
                if(start[u] == start[u+1]){
                     cnt = cnt + 1;
                }
                else
                {
                     next+=to_string(cnt);
                     next+=start[u];
                    
                     cnt = 1;
                     
                }
            }
            
            start = next;
            next.clear();
            
           
                  

        }
        
        
        //reverse(start.begin(),start.end());
        
        return start;
        
        
    }
};
