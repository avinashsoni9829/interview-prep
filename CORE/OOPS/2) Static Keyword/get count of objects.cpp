#include<iostream>
using namespace std;

class counter{
	 int id;
	 static int count;
	 
	 public : 
	   counter(){
	   	   id = ++count;
	   }
	   ~counter(){
	   	  --count;
	   }
	   void getid(){
	   	 cout<<"id : "<<id<<endl;
	   }
	   static void getcnt(){
	   	cout<<"count = "<<count<<endl;
	   }
};

int counter :: count = 0;



int main(){
	  counter id1,id2;
	  counter :: getcnt();
	  
	  counter id3,id4,id5;
	   counter :: getcnt();
	   
	   id1.getid();
	   id2.getid();
	   id3.getid();
	   
	   counter :: getcnt();
	   
	   return  0 ;
	   
	   
	   
}
