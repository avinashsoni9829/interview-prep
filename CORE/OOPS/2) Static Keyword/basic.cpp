/*
   Use of static keyword
*/

#include<iostream>
using namespace std;

class Account{
	public : 
	   int accno;
	   string name;
	   static float roi;
	   Account(int accno,string name)
	   {
	   	  this -> accno = accno;
	   	  this -> name = name;
	   	  
	   }
	   void display(){
	   	  cout<<accno<<" name : "<<name<<" "<<roi<<endl;
	   }
};


float Account::roi = 6.3;

int main(){
	 Account a1 = Account(2003,"fjn");
	 Account a2 = Account(322,"cnfn");
	 a1.display();
	 a2.display();
	 
	 return  0 ;
	 
}



