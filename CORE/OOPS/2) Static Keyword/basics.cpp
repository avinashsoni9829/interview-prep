/* Concept of static Variables */ 

/*
    1) they are initiialized with value = 0 
    2) dont get removed untill the programme ends


*/ 

#include<bits/stdc++.h>
using namespace std;

class Account{
	private : 
	 int balance ;  //  instance  member variable (  if object is created then it will assigned memory)
 	 static float roi; // static member variable  or class variable  (  only memory assigned once and used by all the programms)
	 
	 public:
	 	
	 	void setbalance(int b){
	 		balance = b;
		 }
		 
		 void show(){
		 	 cout<<"Balance = "<<balance<<endl;
		 	 cout<<"roi = "<<roi<<endl;
		 }
		 
		 static void setroi(float  r){
		 	roi = r;
		 	
		 	
		 }
	 	
	 	
};

float Account :: roi  = 3.5f; // initializing the static variable 


int main(){
	 	Account a1 , a2 ;
	 	a1.setbalance(10);
	 	a2.setbalance(11);
	  // about static member functions
		 
		 Account a3;
		 a3.setbalance(11); 
		 
		 a3.setroi(9.2f);
		 
		 Account a4;
		 
		 a4.setbalance(134);
		 a4.setroi(9.3f);
		 
		 a3.show();
		 a4.show();
		 cout<<"----------------------------------- before applying static roi change ----------------"<<endl;
		 
		
		// if we want to call set roi without using object then we have to make it static 
		
		 	
	 	Account ::setroi(9.99f);
	 	
	 	
	 	a3.show();
	 	a4.show();
	 	
	 	
	 	
}


/*
  static member variable : 
  
  
  1) declared inside body of the class
  
  2) also know as class member variable 
  
  3) they must be defined outside the class
  
  4) static member variable does'nt belong to any object , but to whole class
  
  5) there will be only one copy of static member variable to the whole class
  
  6) any object can use the same copy of class variable 
  
  7) they can also be used with class name 
  
  
*/


/*

    static member function : 
    
    
    1)  they are qualified with the keyword static 
    
    2)  they are also called as class member functions 
    
    3)  they can be invoked without any object  
    
    4) they cann only access static member of the class


*/

