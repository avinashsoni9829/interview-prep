
#include<bits/stdc++.h>
using namespace std;

/*
  Try  Catch and Throw  
  
  *  programme statement that you want to monitor for exceptions are contained in a try block 
  *  if any exception occurs within the try block , it is thrown ( using throw  )
  *  the exception  is caught , using catch ,  and  processed .
   
   try and catch dono ek saath aane chahiye 
   
   throw bina try catch ke bhi chal jaayega 
   
   issme terimante function call hoga usse  abort function call hoga 
   

 
*/


int main(){
	  cout<<"welcome"<<endl;
	  int i = 3;
	  try{
	  	if(i == 1 ) throw 10;
	  	if(i == 2) throw "hello";
	  	if(i == 3) throw 4.4;
	  	throw 10;
	  	cout<<"in try"<<endl;
	  }
	  
	  catch(...){
	  	cout<<"all exception handler"<<en
	  }
	  /*
	  this has to be removed if all catch is used 
	  catch(int w){
	  	cout<<"exception = "<<w<<endl;
	  }
	  catch(double f){
	  	cout<<"double exception = "<<f<<endl;
	  	
	  }
	  
	  */
	  cout<<"last line"<<endl;
	  
}


