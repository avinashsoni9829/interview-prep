#include<bits/stdc++.h>
using namespace std;

int main(){
	  
	  int n , m ;
	  cin>>n>>m;
	  
	  int a[n][m];
	  
	  for(int  i = 0 ; i < n ; ++i){
	  	 for(int  j = 0 ; j < m ; ++j){
	  	 	  cin>>a[i][j];
		   }
	  }
	  
	  
	  int ans = -1;
	  
	  for(int i = 0 ; i < n ; ++i){
	  	  int curr = 0 ;
	  	  
	  	   for(int j = 0 ; j < m ; ++j){
	  	   	    curr = curr + (a[i][j] == 1);
			 }
			 
			 ans = max(ans,curr);
	  }
	  
	  cout<<"Max no of 1s are : "<<ans<<endl;
	  
	  
	  
	  
	  
}
