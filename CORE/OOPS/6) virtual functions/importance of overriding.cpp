// example of method overriding importance
/*  

 agar kisi base class ko inherit karte waqt agar aap base class ke kisi fucntion ko modify karke koi kaam karna chahte h  
 to function overriding kare 
 
 

*/ 
#include<bits/stdc++.h>
using namespace std;


class car {
	 public : 
	 void shiftGear(){
	 cout<<"base class called "<<endl;	
	 };
	 
};

class SportsCar : public  car {
	 public :
	 	
	 void shiftGear(){
	 	cout<<"gear change called from derived "<<endl;
	 	 
	 } 
	 
	 
	 
};

int main(){
	 SportsCar  ob;
	 
	 /* 
	    ob.shiftGear();
	 
	 ob.gearchange();
	 
	      now here both the gear change are called which are giving the same functionality 
	     so this is not feasible
	     hence we make a function with same name as the shiftGear() in the sportsCar class which gives different functionality
	     to sports car 
	 */ 
	 
	 ob.shiftGear();
	 
	 
	 car ob1;
	 
	 ob1.shiftGear();
	 
	 
}


