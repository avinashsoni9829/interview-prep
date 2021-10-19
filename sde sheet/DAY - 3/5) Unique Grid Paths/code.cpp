#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
   unique grid paths */
   
   /* flow of ans 
   
      1) recursion 
      
      2) memoization or top down 
      
      3) combinatorics 
   
   
   */
   


  // exponential time  + space

  ll method1(ll x,ll y ,ll n, ll m)
  {  
     
     // breaking case 
     
     if(x>=n or y>=m)  return  0;
     
	 // satisfying constraints
	 
	 if(x == n-1 or y == m-1) return 1;
	 
	 return method1(x+1,y,n,m) + method1(x,y+1,n,m);  
   
 }

  /*  memoization  
       
      time  : O ( n * m)
	  space : O ( n * m) 
      
   */
  const ll mx = 100;
  ll dp[mx][mx];
  ll method2(ll x,ll y ,ll n, ll m)
  {  
     
     // breaking case 
     
     if(x>=n or y>=m)  return  0;
     
	 // satisfying constraints
	 
	 if(x == n-1 or y == m-1) return 1;
	 
	 if(dp[x][y]!= -1)
	 {
	 	  return dp[x][y];
	 }
	 
	 return dp[x][y] = method1(x+1,y,n,m) + method1(x,y+1,n,m);  
   
 }
 
 
 /*
   bottom up dp 
   
   time  : O ( n * m)
   
   space : O ( n * m) 
 
 
 */
 
 int method3(int n,int m)
 {
 	  int dp[n][m];
 	  
 	  for(int i=0;i<n;++i)
 	  {
 	    for(int j=0;j<m;++j)
		 {
		     if(i==0 or j==0)
			 {
			    dp[i][j] = 1; 	
		     }	 
		    else
			{
			    dp[i][j] = dp[i-1][j] + dp[i][j-1] ; 
			} 
 		 
		 
		 }	 
	  }
	  
	  return dp[n-1][m-1];
 }
 
 //  combinatorics  n+m-2 
                 //     C    
                     //   m-1
					 
					    
 int method4(int n,int m)
 {
 	 int N=n+m-2;
 	 int r = m-1;
 	 
 	 int ans = 1;
 	 
 	 for(int i = 1 ; i<=r ; ++i)
 	 {
 	    ans = ans * ( N-r+i) / i;	  
	 }
	 
	 return ans;
	 
 	  
 }
 
 
 
 
  
int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
    // used for method 2 during memoization
    //memset(dp,-1,sizeof(dp));
    
	ll n,m;
    
    cin>>n>>m;
    
    //cout<<method1(0,0,n,m)<<endl;
    //cout<<method2(0,0,n,m)<<endl;
    
   // cout<<method3(n,m)<<endl;
    
    cout<<method4(n,m)<<endl;
}


