// repeat and missing number xor approach  

#include<bits/stdc++.h>
using namespace std;

int main(){
	  int n ; 
	  cin>>n;
	  
	  int a[n];
	  
	  for(int  i = 0 ; i < n ; ++i) cin>>a[i];
	  
	  int xorr = 0 ;
	  int x = 0 , y  = 0 ;
	  
	  // xor of array elements  
	  
	  for(int i  = 0 ; i  < n ; ++i){
	  	  xorr = xorr ^ a[i];
	  }
	  
	  // xor from 1 to n 
	  
	  for(int  i = 1  ;  i <= n ; ++i){
	  	  xorr = xorr ^ i;
	  }
	  
	  // mask 
	  
	  int mask = xorr & (-xorr);
	  
	  //segregation 
	  
	  for(int  i = 0 ;  i < n ; ++i){
	  	   if(a[i] & mask){
	  	   	 x = x ^ a[i];
			 }
			 else
			 {
			 	 y = y ^ a[i];
			 }
	  }
	  
	  for(int i = 1 ; i <=n ; ++i){
	  	  if(i & mask){
	  	  	 x = x ^ i;
			}
			else
			{
				 y =  y ^ i;
			}
	  }
	  
	  // finding the ans
	  
	  int miss = 0 , rep = 0 ;
	  
	  for(int  i = 0 ; i  < n ;  ++i){
	  	  if(a[i] == x){
	  	  	   miss = y;
	  	  	   rep = x;
	  	  	   break;
			}
			else
			if(a[i] == y){
				 rep = y ;
				 miss =x;
				break;
			}
	  }
	  
	  cout<<miss <<" "<<rep<<endl;
	  
	  
}
