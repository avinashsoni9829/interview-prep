#include<bits/stdc++.h>
using namespace std;
/* element  >  n/2   (  majority  element)  */
/*
 ans flow 
 
 1) brute force method   O(n^2) O(1) 
 
 2) using Maps or frequency array    O(n log n ) [map]  or O(n) [freq array ]   and O(N)  space 

 3) using booye moore voting algo  O(n)  + O(1) space 

*/


 int booyemoorevotingalgo(vector<int>a ,int n )
 {
 	    int ans = 0;
 	    int curr = 0;
 	    
 	    for( auto z : a )
 	    {
 	         if( curr == 0 )
			  {
			      ans = z;	  
			  }  
		  	  if( z == ans )
		  	  {
		  	      curr+=1;	  
			  }
			  else
			  {
			  	  curr-=1;
			  }
			  
		}
		
		return ans;
		
 }


int main()
{
	
	int n;
	cin>>n;
	
	vector<int>a(n);
	
	for(auto &z:a) cin>>z;
	
	cout<<booyemoorevotingalgo(a,n)<<endl;
	

}


