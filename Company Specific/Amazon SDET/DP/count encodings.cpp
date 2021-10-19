class Solution {
	public:
	const int modu = 1e9 + 7 ;
		int CountWays(string str){
		    // Code here
		    
		    int n = str.length();
		    
		    int dp[n+1];
		    dp[0] = 1;
		    dp[1] = 1;
		    if(str[0] == '0') return  0 ;
		    
		    for(int i = 2 ; i<=n ; ++i){
		          dp[i]  = 0 ;
		          
		          
		          if(str[i-1] > '0'){
		              dp[i] = dp[i-1];
		              dp[i]%=modu;
		          }
		          
		          if((str[i-2] == '1' or (str[i-2] == '2' and str[i-1] < '7')))
		          {
		              dp[i]+=dp[i-2];
		              dp[i]%=modu;
		          }
		    }
		    
		    return dp[n]%modu;
		    
		}

};
