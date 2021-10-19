#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int n,m;



/*  

   Method 1  :
   
    time  :  O(n * m)
    space  : O( 1)

    Right Rotation 
  
    for - > left rotation rotate the coloumns
  
*/


void printmatrix()
{
	  for(int i=0;i<n;++i)
	  {
	  	  for(int j=0;j<m;++j)
	  	  {
	  	  	 
				 cout<<a[i][j]<<" ";  
		    	
		  }
		  cout<<endl;
		  
	  }
	  
	  
}




void method1()
{
	
	 // step 1 :  take the transpose of the matrix 
	 
	 for(int i=0;i<n;++i)
	 {
	 	  for(int j=0;j<i;++j)
	 	  { 
		   
		   swap(a[i][j],a[j][i]);
		  
		  }
	 }
	 printmatrix();
	 
	 // step 2 :  reverse all the rows of the matrix 
	 
	 for(int i=0;i<n;++i)
	 {
	 	 int low = 0;
	 	 int high = m-1;
	 	
	 	 while(low<=high)
	 	 {
	 	    swap(a[i][low],a[i][high]);
			
			low+=1;
			high-=1;	  
         }
         
	 }
	   
}



int main()
{
	
	 cin>>n>>m;
	
	     // dont use vector here as while reversing we will need to use the normal matrix reversing not the stl method
	
	 for(int i=0;i<n;++i)
	 {
	 	  for(int j=0;j<m;++j)
	 	  {
	 	  	 
				cin>>a[i][j]; 
		      
		  }
	 }
	 
	 
	 method1();
	
	 printmatrix();

}


