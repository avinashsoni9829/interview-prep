#include<bits/stdc++.h>
using namespace std;

int dp[100000];

int recur(vector<int>a,int n){
	 if(n<=0) return  0 ;
	 
	 int mx_profit = INT_MIN;
	 
	 if(dp[n]!=-1){
	 	return dp[n];
	 }
	 
	 for(int  i = 0 ; i < n ; ++i){
	 	  mx_profit = max(mx_profit,recur(a,n-i-1) + a[i]);
	  }
	  
	  return dp[n] = mx_profit;
	  
}

/*
    time : O ( n * n )
    space : O(n)
    

*/ 

int dpsoln(vector<int>a,int n){
	  int dp[n+1] ={0};
	  dp[0] = 0 ;
	  
	  for(int i = 1 ; i <=  n ; ++i){
	        int mx  = INT_MIN;
	        for(int j = 0  ; j < i ; ++j){
	        	  mx = max(mx,a[j] + dp[i-j-1]);
			}
			dp[i] = mx;
	  }
	  
	  return dp[n];
	  
}



int main(){
	
	  memset(dp,-1,sizeof(dp));
	  int n ;
	  cin>>n;
	  
	  vector<int>a(n);
	  
	  for(auto &z:a) cin>>z;
	  
	  
	  //cout<<recur(a,n)<<endl;
	  cout<<dpsoln(a,n)<<endl;
	  
}
