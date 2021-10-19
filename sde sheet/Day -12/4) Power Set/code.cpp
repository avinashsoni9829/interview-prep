power set 

void pSet(vector<ll>a,int n)
{
	  for(ll i=0;i<(1<<n);++i)
	  {
	  	vector<ll>tmp;
	  	   for(int j=0;j<n;++j)
	  	   {
	  	   	   if(i&(1<<j))
	  	   	   {
	  	   	   	   tmp.push_back(a[j]);
	  	   	   }
	  	   }
	  	  
	  	   subs.push_back(tmp);
	  	   tmp.clear();
	  }
	    
}
