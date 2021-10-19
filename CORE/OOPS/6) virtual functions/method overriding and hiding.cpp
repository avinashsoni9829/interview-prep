/* method oveeriding   , method hiding */


#include<bits/stdc++.h>
using namespace std;

class A{
	public : 
	void f1() { };
	void f2() { };
};

class B : public A {
	void f1() { };   //  method overriding  sab kuch same  h yaha pe base class jaise  arguments bhi same h  
	void f2(int x){ }; //  method hiding   sab kuch same  h except the arguments 
	
	
};


int main(){
	B ob1;
	ob.f1(); // early binding hoga yaha pe  , B class me dekhega compiler aur waha f1 h to usko call kar dega 
	ob.f2(); //  this will give error , compiler B class me dekhega aur waha use f2 naam ka function mil jaayega but waha pe argumnet
	         //  same nahi h to compiler kabhi bhi  base class me nahi jaayega aur error show karega 
	         
	ob.f2(4); //  works 
	
}
