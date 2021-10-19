count number of 1's

int basic(int n){
	    int count = 0;
		for(int i = 0 ; i < 32;++i){
			if(n&(1<<i)){
				count = count + 1;
			}
		}
		
		return count;
}




int setbitcount(int n){
	
	int count = 0;
	
	while(n){
		count = count + n&1;
		n>>=1;
	}
	
	return count;
	
}


int brainkarnighanalgo(int n){
	  int count = 0 ;
	  
	  while(n){
	  	 n = n & (n-1); // unset the rightmost set bit
	  	 count = count + 1;
	  }
	  
	  return count ;
}



