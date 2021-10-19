// subarray with given  xor value

int find(vector<int>a,int n ,int k ){
	  map<int,int>mp;
	  int ans = 0  , curr = 0;
	  
	  for(int i = 0 ; i <  n ; ++i){
	  	   curr = curr ^ a[i];
	  	   ans = ans + (curr == k);
	  	   
	  	   if(mp.find(curr^k)!=mp.end()){
	  	   	   ans =  ans + (mp[curr^k]);
	  	   	}
	  	   	
	  	   	mp[curr]++;
	  }

    print(ans);
    
}

