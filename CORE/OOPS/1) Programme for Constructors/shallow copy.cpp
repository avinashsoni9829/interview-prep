#include<iostream>
using namespace std;
#define debug(a) cout << #a << "=" << a << ' '<<endl;

class box{
	private : int l,b,h;
	public  : 
	    void set_dimensions(int l1,int b1,int h1){
	    	 l = l1;
	    	 b = b1;
	    	 h = h1;
		}
		void show_data(){
			debug(l);
			debug(b);
			debug(h);
	     cout<<"---------------------------------------------------"<<endl;
	     
		}
		
};

int main(){
	box b1,b3;
	b1.set_dimensions(13,24,44);
	b1.show_data();
	
	// shallow copy during object initiation done by copy constructor 
	
	box b2 = b1;
	b2.show_data();
	
	// copy done using assignment operator
	b3 = b1;
	b3.show_data();
	
	
	
}
