//largest subarray with sum = 0


int ans(vector<int>a){
	  int n  = a.size();
	  int res = INT_MIN;
	  int sum  = 0 ;
	  map<int,int>mp;
	  
	  for(int i  = 0 ; i < n ; ++i){
	  	  sum = sum + a[i];
	  	  
	  	  if(sum == 0) res = i + 1;
	  	  
			if(mp.find(sum)!=mp.end()){
	  	  	   res = max(res , i - mp[sum]);
	  	   }
	  	   else
		   mp[sum] = i ;
	  	   
	  }
}


