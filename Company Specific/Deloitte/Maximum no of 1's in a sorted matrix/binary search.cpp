#include<bits/stdc++.h>
using namespace std;

/*
   time : O( n * logm)
   
   space : O(1)
   
   


*/

int main(){
	  
	  int n , m ;
	  cin>>n>>m;
	  
	  int a[n][m];
	  
	  for(int  i = 0 ; i < n ; ++i){
	  	 for(int  j = 0 ; j < m ; ++j){
	  	 	  cin>>a[i][j];
		   }
	  }
	  
	  /*
	   
	      0  1 1 1 
		  0  0 1 1
		  1  1 1 1 
		  0  0 0 0
		   
	  
	  */
	  
	  
	  // using binary search
	  int ans = -1;
	  for(int i = 0 ; i < n ; ++i){
	  	   int curr = 0 ;
	  	   
	  	   int low = 0 , high = m - 1;
	  	   
	  	   while(low <= high){
	  	   	     
	  	   	      int mid =  low + (high - low ) / 2;
	  	   	       
	  	          if((a[i][mid] == 0 or a[i][mid-1] == 0) and a[i][mid] == 1 ){
	  	          	 curr =  mid;
	  	          	 break;
				  }
				  else
				  if(a[mid] == 0){
				  	  low = mid + 1;
				  }
				  else
				  {
				     high = mid - 1; 	 
				  } 	      
	  	   	   
	  	   	   
			 }
			 
			 
			 ans = max(ans , m - curr);
			 
	  }
	  
	  
	  
	  
	  cout<<"Max no of 1s are : "<<ans<<endl;
	  
	  
	  
	  
	  
}
