//minimum number of stations required for a railway station 
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

