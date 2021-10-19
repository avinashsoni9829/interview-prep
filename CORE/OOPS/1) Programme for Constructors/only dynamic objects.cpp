#include<iostream>
using namespace std;

class Test{
	private :
	/* Private Destructor 
	   As Dynamically Allocated Object Memory is Assigned By Heap
	   so they wont show any problem
	   but non - dyanamic allocation would need  destructor to remove them from stack once not in use 
	   so it will generate compilation error 
	   
	   
	*/ 
	~Test() {
		 cout<<"Destructor called"<<endl;
		 
	}
	public : 
	Test() { 
	    cout<<"Object Created"<<endl;
	    
	}
	/*
	   In order to avoid memory Leakage !
	*/
 	friend void destructorop(Test * );
};

void destructorop(Test  * ptr){
	delete ptr;
	cout<<"Object Removed "<<endl;
	
}


int main(){
	
	 
	 
	 Test * a = new Test;
	 destructorop(a);
}
