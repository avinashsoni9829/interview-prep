/*
Add 1 to a given number

flip all the 1's after rightmost 0

and finally flip the rightmost 0

*/

#include<bits/stdc++.h>
using namespace std;

int addone(int n){
	 int m = 1;
	 
	 while(n&m){
	 	n = n^m;
	 	m<<=1;
	 }
	 
	 n = n ^ m;
	 
	 return n;
}

int main()
{
	
	
	int  n ;
	cin>>n;
	
	cout<<"result is : "<<addone(n)<<endl;
	
}


