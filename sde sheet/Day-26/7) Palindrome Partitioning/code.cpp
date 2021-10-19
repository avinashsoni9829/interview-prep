/* PalinDrome partitioning */

#include<bits/stdc++.h>
using namespace std;
//*   method 1 :  recursion     exponential time complexity  */ 
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

int recur(string s,int  i , int j){
	 
	 
	 if( i>=j or isPalindrome(s,i,j))
	 	return 0;
	 
	 
	 int ans = INT_MAX;
	 int cnt;
	 
	       for(int k = i ; k < j  ; ++k){
	 	  cnt = recur(s,i,k) + recur(s,k+1,j);
	 	  cnt = cnt + 1;
	 	  
	 	  ans = min (ans,cnt);
	 }
	 
	 return ans;
}

/*
   MCM approach 
   
   time : O( n * n * n )

*/


int dpsoln(string s){
	int n = s.length();
	
	int dp[n][n];
	
	bool vis[n][n];
	
	for(int i = 0 ; i< n ; ++i){
		dp[i][i] = 0;
		vis[i][i] = true;
	}
	
	
	for(int  len = 2 ;  len <= n ;  ++len){
		  for(int i = 0 ; i < n - len + 1 ; i++){
		  	  int j = i + len - 1;
		  	  
		  	  if(len == 2){
		  	  	 vis[i][j] = (s[i] == s[j]);
		  	  	 
				}
				else
				{
					 // last should be equal and in between it should be palindrome
					  vis[i][j] = (s[i] == s[j]) and vis[i+1][j-1];
				}
				
				if(vis[i][j] == true){
					 dp[i][j] = 0;
				}
				else
				{
					  dp[i][j] = INT_MAX;
					  
					  for(int  k = i ; k < j ; ++k){
					  	dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] +1) ;
					  }
				}
		  }
	}
	
	return dp[0][n-1];
}
/*
    time : O ( n * n )
    


*/

int optimal(string s){
	  int cut[s.length()];
	  
	  bool dp[s.length()][s.length()];
	  
	  memset(dp,false,sizeof(dp));
	  
	  for(int  i = 0 ; i < s.length() ; ++i){
	  	  int mincut =  i ;
	  	  
	  	  for(int j = 0 ; j <=i  ; ++j){
	  	  	  if(s[i] == s[j] and ((i + j < 2) or dp[j+1][i-1]))
	  	  	  {
	  	  	      dp[j][i] = true;
	  	  	      mincut = min(mincut, j == 0 ? 0 : cut[j-1] +  1);
			  }
			}
			cut[i] = mincut;
	  }
	  
	  return cut[s.length() - 1];
	  
	  
}






int main(){
	   string s;
	   cin>>s;
	   
	   //cout<<recur(s,0,s.length() - 1)<<endl;
	   
	  // cout<<dpsoln(s)<<endl;
	   
	   cout<<optimal(s)<<endl;
	   
}
