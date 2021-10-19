class Solution {
public:
    /*
       time : O(n)
       space : O(n)
       
    */
    int countBinarySubstrings(string s) {
        
        vector<int>blocks;
        
        int n = s.length();
        
        char curr = s[0];
        int count = 1;
        for(int  i = 1  ; i  < n ; ++i){
             if(s[i] == curr){
                 count = count + 1; 
             }
            else{
                blocks.push_back(count);
                count = 1;
                curr = s[i]; 
                
            }
        }
        
        blocks.push_back(count);
        
        
        
        int ans = 0 ;
        
        for(int i = 0 ; i < (int)blocks.size() - 1 ; ++i){
             ans = ans  + min(blocks[i] , blocks[i+1]);
        }
        
        return ans;
        
        
    }
};
