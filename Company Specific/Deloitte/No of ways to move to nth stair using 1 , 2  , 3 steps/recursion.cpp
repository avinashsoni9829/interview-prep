#include<bits/stdc++.h>
using namespace std;

/*
time : O (3 ^ n)
space : O(1)

*/

int ways(int n ){
	  if(n==0 or  n==1){
	  	 return 1;
	  }
	  
	  if(n==2){
	  	 return 2;
	  }
	  
	  return ways(n-1) + ways(n-2) + ways(n-3);
	  
	  
}

int main(){
    int n ;
    cin>>n;
    
    cout<<ways(n)<<endl;
}
