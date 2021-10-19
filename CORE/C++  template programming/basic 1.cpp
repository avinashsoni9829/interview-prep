#include<bits/stdc++.h>
using namespace std;

template < typename  T > 
T maxx ( T x , T y ){
	 return  x > y ? x : y ;
	 
}


int main(){
	  cout<<maxx<int>(3,5)<<endl;
	  cout<<maxx<char>('q','f')<<endl;
      cout<<maxx<double>(9.335 , 9.336)<<endl;
	  	  
}
