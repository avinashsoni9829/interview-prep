/* Shallow and deep copy*/

#include<iostream>
using namespace std;
#define debug(a) cout << #a << "=" << a << ' '<<endl;
class Base{
	private : 
	int * _ptr;
	int _val;
	public : 
	Base() : _ptr{new int(0)} , _val{0} {}
	
	
	
	/* setters and getters */
	
	void setPtr(int ptr) { *_ptr = ptr; }
	void setVal(int val) {_val = val;}
	int getPtr() { return *_ptr ;}
	int getVal() { return _val;}
	
};



int main(){
	Base b1;
	b1.setPtr(10);
	b1.setVal(15);
	
	Base b2 = b1;
	b2.setPtr(50);
	
	debug(b1.getPtr());
	debug(b1.getVal());
	debug(b2.getPtr());
	debug(b1.getVal());
	
	
	
}
