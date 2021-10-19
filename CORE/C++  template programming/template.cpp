/*  
 function    template in c++ 
   
   template < class type > type func_name (type arg1 , .... );
   
*/



#include<bits/stdc++.h>
using namespace std;

template < class X > 
X mx ( X a , X b ){
	
	 return max(a,b);
}

template < class x , class y > 
x mx (x a  , y b ){
	
	if(a>b) return a;
	return b;
}



int main(){
	cout<<mx(3,5)<<endl;
	cout<<mx(4.5f , 55.33f)<<endl;
	
	
	
}
