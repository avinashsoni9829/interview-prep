#include<bits/stdc++.h>
using namespace std;
/* count number of subarray having the xorr value k  */


/*
  flow of ans  : 
  
  1) brute force  O(n ^3 )  ->  O(n^2) 
  2) optimal Using Hashing

*/

/* --------------------------------------- METHOD 1 ----------------------------------------- */

/*
    time : O(n^2)
    space : O(1)
 
 */
  
  int method1(vector<int>a,int n,int k)
  {
  	   int ans = 0 ;
  	   for(int i =  0 ;  i < n; ++i)
  	   {
  	   	  int curr = 0 ;
  	   	  for(int j = i; j < n ; ++ j)
  	   	  {
  	   	  	 curr = curr ^ a[j];
  	   	      ans = ans + (curr == k);
			  
			 
			  	   	  
		  }
		  
	   }
	   
	   return ans;
	   
  }
  
  /* --------------------------------------- METHOD 2 ----------------------------------------- */
  
  /* 
       time : O(n * logn)
       space : O(n)
  
  */
  
  
  int method2(vector<int>a,int n,int k)
  {
  	  map<int,int>mp;
  	  
  	  int ans = 0;
  	  int curr = 0;
  	  
  	  for(int i = 0 ; i < n ;++i)
  	  {
  	     
		    curr = curr  ^ a[i];
			
			ans =  ans + (curr == k );
			
			if(mp.find(curr ^ k) != mp.end())
			{
			    ans = ans + mp[curr^k];	 
			}
			
			mp[curr]++;	  
	  }
	  
	  return ans;
	  
  }




int main()
{
	int n;
	cin>>n;
	
	vector<int>a(n);
	
	for(auto &z:a) cin>>z;
	
	int  k ;
	cin>>k;
	
	//cout<<method1(a,n,k)<<endl;
	cout<<method2(a,n,k)<<endl;
   
}


