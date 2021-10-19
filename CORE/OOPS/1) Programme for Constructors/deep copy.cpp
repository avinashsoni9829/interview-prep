#include<iostream>
using namespace std;
#define debug(a) cout << #a << "=" << a << ' '<<endl;


class box {
	private : int l , *b , h;
	public : 
	box(){
		b = new int;
	}
	void set(int l1,int b1,int h1){
		l1  = l ;
		*b =  b1;
		h = h1;
	}
	void show(){
		debug(l);
		debug(*b);
		debug(h);
	}
	
	// deep copy constructor
	
	box(box & deep){
		 l = deep.l;
		 b = new int;
		 *b = *(deep.b);
		 h = deep.h;
	}
	
	~box(){
		delete b;
	}
};


int main()
{
	  box f;
	  f.set(12,13,14);
	  f.show();
	  
	  box s = f;
	  s.show();
	   
	  
}



