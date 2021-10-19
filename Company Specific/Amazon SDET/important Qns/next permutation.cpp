//next permuatation 

void nextpermutation(vector<int>a){
	  int n = a.size();
	  
	  int i ;
	  
	  for(i = n - 2 ; i >= 0 ; i--){
	  	  if(a[i] < a[i + 1]){
	  	  	      break;
			}
	  }
	  
	  if( i < 0 ) reverse(a);
	  
	  else
	  {
	  	 for(int last = n - 1 ; last > i ; last --){
	  	 	   if(a[last] > a[i]){
	  	 	   	  break;
				  }
		   }
		   
		   swap(a[last] , a[i]);
		   
		   reverse( i + 1 , end())
	  }
}
