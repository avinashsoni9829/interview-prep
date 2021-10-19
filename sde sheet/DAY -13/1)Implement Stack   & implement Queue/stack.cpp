#include<bits/stdc++.h>
using namespace std;

const int max = 100;

class stack{
	int top;
	public:
		int a[max];
		bool push(int x);
		int pop();
		int peek();
		bool isEmpty();
};


bool stack :: push(int x)
{
	 // check for top
	 
	 if(top >= max - 1)
	 {
	 	 cout<<"Stack is full"<<endl;
	 	 return;
	 }
	 else
	 {
	 	  
	 	  top = top + 1;
	 	  a[top] = x;
	 	  cout<<x<<" is pushed in stack"<<endl;
	 	  
	 }
	 
}

int stack :: pop()
{
	  // check for empty
	  
	  if(top < 0)
	  {
	  	 cout<<"Stack underflow"<<endl;
	  	 return;
	  }
	  else
	  {
	  	   int tp = a[top];
	  	   top = top - 1;
	  	   return tp;
	  	   
	  }
}


int stack :: peek()
{
	  if(top<0)
	  {
	  	 cout<<"Stack is empty"<<endl;
	  	 return;
	  }
	  else
	  {
	  	 return a[top];
	  	 
	  }
}


bool stack :: isEmpty()
{
	 return top < 0 ;
}



