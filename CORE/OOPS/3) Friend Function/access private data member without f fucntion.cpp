#include<bits/stdc++.h>
using namespace std;

class test{
	  private :  int x,data;
	  public : 
	  test() { data = 0; }
	  int getdata() { return data;} 
	  int getx(){    
	       return x;
	  }
};


int main(){
	
	test ob;
	int  *  ptr = (int *) &ob;
	*(ptr+1) = 10;
	
	cout<<ob.getdata()<<endl;
	cout<<ob.getx()<<endl;
	
	
	 
}
