#include<bits/stdc++.h>
using namespace std;

class construct{
	private :  int x , y;
	public:
		// Default Constructor 
		construct(){
			 x = 0 ;
			 y = 0 ;
		}
		// Parameterized Constructor 
		construct(int xx,int yy){
			 x = xx;
			 y = yy;
		}
		
		// Copy constructor 
		construct(const construct & ob){
			x = ob.x;
			y = ob.y;
		}
		
		// Method of class
		void display(){
			cout<<"x = "<<x<<endl;
			cout<<"y = "<<y<<endl;
			
			cout<<"-------------------------------"<<endl;
			
	     	}
		
};

int main(){
	/*  Default constructor  */
	 construct ob;
	 ob.display();
	 /*  Parameterized constructor  */
	 construct pop(3,4);
	 pop.display();
	 /*  Copy  constructor  */
	 construct obc;
	 obc = pop;
	 obc.display();
	 	 /*  Copy  constructor  [ another way of calling it ] */
	 construct obc1(pop);

	 obc1.display();
	 
	 
	 
	 
}
