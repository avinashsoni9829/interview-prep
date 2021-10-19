/*
  deep concept of virtual function 
  how virtual function  works
  
*/

#include<bits/stdc++.h>
using namespace std;

class A{
	public :
		void f1(){
	        cout<<" base class f1"<<endl;
					
		};
		
		virtual  void f2(){
			 cout<<" base class f2"<<endl;
		};
		
		virtual void f3(){
			 cout<<" base class f3"<<endl;
		};
		
		virtual void f4(){
			 cout<<" base class f4"<<endl;
		};
		
}; 


class B : public A{
	public : 
	void  f1(){
		 cout<<" derived  class f1"<<endl;
	};
	void f2(){
		cout<<" derived  class f1"<<endl;
	};
	
	void f4(int x){
		cout<<" derived  class f1"<<endl;
	};
	
};


int main(){
	  A * p , o1;
	  p = & o1 ;
	  
	  p -> f1(); //  early binding
	  p -> f2(); //  dynamic binding
	  p -> f3(); //  dynamic binding
	  p -> f4(); //  dynamic binding
	  p -> f4(5);//  early binding 
	  
	  
}


/*

   agar kisi class me virtual function  h 
   
   to compiler uske lie khud se ek *_vptr pointer bana dega  
    jo ki memory me dekh sakte h aur ye inherit bhi hoga agar iss class ko koi derive kar rhaa  h toh 
    
    iske saath compiler ek static array banate h ( jisme pointer hote h ( virtual   function pointers store hote h )) isko v table bolte h 
    
    jis bhi class me virtual function h  uska vtable banega aur uski sabhi derived classes ka bhi vtable banega 
    
    
    *_vptr me vtable ka addresss hota h 
    



*/
