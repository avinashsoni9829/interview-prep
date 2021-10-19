// largest subarray with no repeating values 

int method4(string s, int n ){
 	  map<char,int>mp;
 	  
 	  int i = -1; 
 	  int j = -1;
 	  int ans = 0 ;
 	  
 	  while(true){
 	  
	      bool flag1 = false;
		  bool flag2 = false;
		  
		  while(i<n-1){
		  	  flag1 = true;
		  	
		  	i = i + 1;
		  	
		  	mp[s[i]]++;
		  	
		  	if(mp[s[i]] == 2){
		  		 break;
			  }
			  else
			  {
			  	 ans = max(ans, i - j );
			  }
		  }
		  
		  while(j<i){
		  	 flag2 = true;
		  	 
		  	 j = j + 1;
		  	 
		  	 mp[s[j]]--;
		  	 
		  	 if(mp[s[j]] == 1){
		  	 	  break;
			   }
		  }
		  
		  if(flag1 == false and flag2 == false)
		  {
		  	 break;
		  }
		  
		  
		  	 
	   }
	   
	   
	   return ans;
	   
	   
	   
 	  
 }


