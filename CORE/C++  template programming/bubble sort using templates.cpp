#include<bits/stdc++.h>
using namespace std;

template < class T > 

void bubblesort(T a[] , int n){
	  
	  for(int  i = 0 ; i <  n - 1 ; ++i){
	  	 for(int  j =  n - 1  ; i < j ;  j--){
	  	 	   if(a[j] < a[j-1]){
	  	 	   	swap(a[j] , a[j-1]);
				  }
		   }
	  }
}

template < typename T > 
void print(T a[],int n){
	  for(int i = 0 ; i <  n ; ++i){
	  	cout<<a[i]<<" ";
	  }
	  
	  cout<<endl;
}


int main(){
	int a[5] = {10,20,30,40,1};
	double b[5] = {8.34 , 0.3 , 1.34 , 6.14 , 89.245};
	
	bubblesort<int>(a,5);
	bubblesort<double>(b,5);
	
	print<int>(a,5);
	print<double>(b,5);
	

	
}
