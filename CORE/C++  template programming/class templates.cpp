/*
   generic class 
   class templates
*/

#include<bits/stdc++.h>
using namespace std;

template <class X> 



class ArrayList{
	private : 
	
	struct  ControlBlock
	{
		int capacity ;
		X * arr_ptr;
	};
	
	ControlBlock * s;
	
	public :
		 ArrayList(int capacity){
		 	s = new ControlBlock;
		 	s -> capacity = capacity ;
		 	s -> arr_ptr = new X(s->capacity);
		 }
		 
		 void addElement(int idx ,X data){
		 	if(idx >=0 and idx <= s->capacity - 1){
		 		 s->arr_ptr[idx] = data;
		 		}
		 		else
		 		{
		 			 cout<<"\n array idx is not valid \n"<<endl;
				 }
		 }
		 
		 void viewElement(int idx, X &data)
		 {
		 	if(idx >=0 and idx<=s->capacity - 1){
		 		 data = s->arr_ptr[idx];
		 		 
			 }
			 else
			 {
			 	 cout<<"\n array idx is not valid  \n"<<endl;
			 	 
			 }
		 }
		 
		 void viewList(){
		 	 int i ;
		 	 for(int  i = 0 ; i < s -> capacity - 1 ; ++i){
		 	 	 cout<<" "<<s -> arr_ptr[i];
				    	
			  }
		 }
		 
		 
		 
};


int main(){
	int data;
	 ArrayList <int>list1(10);
	 ArrayList <float>list2(3);
	 list2.addElement(0,33.22f);
	 list2.addElement(1,32.2f);
	 list2.viewList();
	 
	 list1.addElement(0,32);
	 list1.addElement(1,33);
	 list1.addElement(2,45); 
	 
	 list1.viewList();
	 
}
