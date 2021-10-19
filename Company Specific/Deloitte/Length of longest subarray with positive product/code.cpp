/*

Length of longest subarray with positive product
*/


#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
	  int pos = 0 , neg = 0 , ans = 0 ;
	  
	  for(int i = 0 ; i < n ; ++i){
	  	
	  	 if(a[i] == 0){
	  	 	 pos = 0 ;
	  	 	 neg = 0 ;
		   }
		   else
		   if(a[i] > 0){
		   	   pos = pos + 1;
		   	   
		   	   if(neg!=0){
		   	   	neg = neg + 1;
				
				}
			    ans = max(ans ,pos);	  
		   }
		   else
		   {
		       swap(pos , neg);
			   
			   neg = neg + 1;	 
		   
		       if(pos!=0){
		       	 pos = pos  + 1;
			   }
			   
			   ans = max(ans , pos);
		   
		   } 
	  }
	  
	  return ans;
	  
}
