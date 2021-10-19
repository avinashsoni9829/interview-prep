#include<bits/stdc++.h>
using namespace std;

/*
   time : O( n * n)
   space : O(1)
   
*/



int findPlatform(int arr[] , int dep[ ] , int n ){
	
	int curr_need = 1 , ans = 1;
	
    for(int  i = 0 ;  i <  n ; ++i){
    	  curr_need = 1;
    	  for(int j = i + 1 ; j  < n ; ++j){
    	  	  
    	  	  if(
				 (arr[i] >= arr[j] and dep[j]  >= arr[i]) or
				 (arr[j] >= arr[i]  and dep[i] >= arr[j]) 
				)
				{
				 	curr_need  = curr_need + 1;
				 }
		  }
		  ans = max(ans , curr_need);
	}
	
	return ans;
	
}

/* optimal solution 
time : O( n log n)
space : O(1)
*/

int optimal(int arr[] , int dep[] , int n){
	  sort(arr , arr + n);
	  sort(dep , dep + n);
	  
	  int need = 1 , ans = 1;
	  
	  int i = 1 , j = 0 ;
	  
	  while( i < n and  j < n){
	  	
	  	  if(arr[i] <= dep[j]){
	  	  	 need = need + 1;
	  	  	 i = i + 1;
			}
			else
			if(arr[i] > dep[j]){
				 need = need -  1;
				 j = j + 1;
			}
			
			ans = max(ans , need);
	  }
	  
	  return ans;
	  
}


int main()
{
	   int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
       int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };       
       int n = sizeof(arr) / sizeof(arr[0]);
       cout << "Minimum Number of Platforms Required = "
            << findPlatform(arr, dep, n);
       return 0;
       
}
