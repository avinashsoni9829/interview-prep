class Solution {
public:
    bool isMatch(string s, string p) {
       int m = p.length();
       int n = s.length();
        
       int dp[m + 1][n + 1];
       memset(dp, 0 , sizeof(dp));
        
       dp[0][0] = 1; //  empty string can match the empty string 
        
        for(int  i = 1 ; i <= m; ++i){
              if(p[i - 1] == '*'){
                   dp[i][0] = dp[i - 1][0];
              }
        }
        
        
        for(int  i = 1 ; i <= m ;  ++i){
              for(int j =  1 ; j <= n ; ++j){
                     if(p[i - 1] == s[j -1] or p[i -1 ] == '?'){
                           dp[i][j] = dp[i - 1][j  - 1];
                     }
                     else
                     {
                          if(p[i - 1] == '*'){
                                dp[i][j] = dp[i - 1][j] or dp[i][ j - 1];
                          }
                     }
              }
        }
        
        return dp[m][n];
        
    }
};
