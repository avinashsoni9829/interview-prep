/*

  Swap two members of a class using friend function
  
*/

#include<bits/stdc++.h>
using namespace std;

class test{
	
	 private : int x;
	 public : 
	 test(int x){
	 	 this -> x = x;
	 }
	 friend void swap(test& ,test&);
	 
};


void swap(test& ob1 ,test& ob2){
	   cout<<"value before swap are  : "<<ob1.x<<" "<<ob2.x<<endl;
	   
	   int temp ;
	   
	   temp = ob1.x;
	   ob1.x = ob2.x;
	   ob2.x = temp;
	   
	   cout<<"value after swap are  : "<<ob1.x<<" "<<ob2.x<<endl; 
}



int main(){
	 test ob1(3),ob2(5);
	 swap(ob1,ob2);
	 return 0;
	 
	
}
