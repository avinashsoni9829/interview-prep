#include<bits/stdc++.h>
using namespace std;

class A{
	public : 
	static int a;
	A(){
		 cout<<a<<endl;
		 a = a + 1;
	}
	
};

int A :: a = 1;


int main(){
	 int  n = 100;
	 A obj[n];
	 return 0 ;
	 
}
