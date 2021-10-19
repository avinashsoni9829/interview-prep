#include<bits/stdc++.h>
using namespace std;
#define k 3


vector<vector<int>> mul(vector<vector<int>>a , vector<vector<int>>b){
	vector<vector<int>> ans(4 , vector<int>(4));
	
	for(int  i = 1; i <=k ;++i){
		 for(int  j = 1 ; j<=k ; ++j){
		 	for(int u = 1 ; u<=k;++u){
		 		 ans[i][j] = (ans[i][j] + a[i][u] * b[u][j]);
		 		 
			 }
		 }
	}
	
	return ans;
}



vector<vector<int>>expo(vector<vector<int>>t,int n){
	
	if(n==1) return t;
	
	if(n&1){
		return mul(t,expo(t,n-1));
	}
	else
	{
		 vector<vector<int>>x = 	expo(t,n/2);
		 return mul(x,x);
		 
	}
}



int compute(int n){
	
	if(n==0) return 1;
	if(n==1) return 1;
	if(n==2) return 2;
	
	
	int dp[k+1]={};
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	/*
	      0  1 0 
	      0  0 1
	      3  2 1
	
	*/
	
	vector<vector<int>>t(k+1 , vector<int>(k+1));
	
	for(int i = 1; i <= k ; ++i){
		 for(int j = 1 ; j<= k ; ++j){
		 	 
		 	 if(i<k){
		 	 	if(j==i+1){
		 	 		t[i][j] = 1;
				  }
				  else
				  {
				  	 t[i][j] = 0;
				  }
				  continue;
			  }
			  t[i][j] = 1;
		 }
	  }
	  
	  
	  
	  t = expo(t,n-1);
	  
	  int ans = 0 ;
	  
	  for(int i  = 1 ; i<=k ; ++i){
	  	 ans = ans + t[1][i] * dp[i];
	  }
	  
	  
	  return ans;
}


int main(){
	
	int n ;
	cin>>n;
	
	cout<<compute(n)<<endl;
	
}
