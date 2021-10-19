#include<bits/stdc++.h>
using namespace std;
const int mx = 1000;
int dp[mx]; 


int ways(int n ){
	  if(n==0 or  n==1){
	  	 return 1;
	  }
	  
	  if(n==2){
	  	 return 2;
	  }
	  
	  if(dp[n]!=-1)
	  return dp[n];
	  
	  return dp[n] = ways(n-1) + ways(n-2) + ways(n-3);
	  
	  
}

int main(){
	memset(dp,-1,sizeof(dp));
	
    int n ;
    cin>>n;
    
    cout<<ways(n)<<endl;
}
