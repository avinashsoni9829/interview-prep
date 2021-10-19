#include<bits/stdc++.h>
using namespace std;

int n,m;

int a[100][100];


/*   Search in a 2-D matrix      */

// method 1  :  Brute force  Time : O(n * m)  space : O(1)

 void method1(int val)
 {
 	   bool found=false;
 	   
 	   for(int i=0;i<n;++i)
 	   { 
	     for(int j=0;j<m;++j)
		 {
		 	 if(a[i][j]==val)
		 	 {
		 	     
				  found=true;
				  
				  break;  	 
			    
			 }
		 }	
	   }
	   
	   if(found)
	   {
	   	  cout<<"Found"<<endl;
	   }
	   else
	   {
	   	  cout<<"Not Found"<<endl;
	   }
	   
 }
 
 
 //  Method 2 :  Binary Search on each row    time : (N*Log(M))  space : O(1)
  
 void method2(int val)
 {
 	   bool found=false;
 	   
 	   for(int i=0;i<n;++i)
 	   {
 	      
 	       int low=0,high=m-1;
 	       
 	       while(low<=high)
 	       {
 	         int mid = (low + high) / 2;
 	         
 	         if( a[i][mid] == val)
 	         {
 	             
 	             found = true;
 	             break;
			  }
			  else
			  if(a[i][mid] > val)
			  {
			  	    high= mid - 1;
			  }
			  else
			  {
			  	  low = mid + 1;
			  }
			     	  
		   }
		   
		   if(found)
		   {
		   	  break;
		   }
		    	   
		
	   }
	   
	   
	   if(found)
	   {
	   	  cout <<" found "<<endl;
	   	  
	   }
	   else
	   {
	   	  cout<<" Not Found "<<endl;
	   	  
	   }
 }
 
 
 // Method 3 :  Binary Search On The Whole 2-D matrix 
 /*
    
     time  :  O(log ( n * m )
     space :  O(1)
     
  
 */  
 
 void method3(int val)
 {  
 
       int low = 0 , high = n * m - 1;
       
       bool found = false;
       
       while( low <= high )
       {
       	   int mid = (low + high) / 2 ;
       	   
       	   int x_coordinate = mid / m;
       	   int y_coordinate = mid % m;
       	   
       	   if( a[x_coordinate][ y_coordinate] == val )
       	   {
       	       	found = true;
			    
				break;  
		   }
		   else
		   {
		   	   if( a[ x_coordinate][y_coordinate] > val)
		   	   {
		   	   	   
			       high = mid - 1;
			   }
			   else
			   {
			   	   low = mid + 1;
			   }
		   }
	   }
	   
	   if( found )
	   {
	   	  cout<<"Found"<<endl;
	   }
	   else
	   {
	   	  cout<<"Not Found"<<endl;
	   }
  
 }
 
 
 
 /*
 
 
    Another Variant Of the Same Question 
    
    when both row and coloumn are sorted 
    
   
 
 */
 
 // Solution for variant :
 
 /*
      int low = 0 , high = m-1 
	  
	  start from top right corner
	  
	  if val is   > req then move left otherwise move down 
	  
	  time complexity : O(n + m)
	  space complexity : O( 1)
	  
*/

void variant2(int val)
{
	   int low=0,high=m-1;
	   bool found = false;
	   while(low>=0 and low<=n-1 and high>=0 and high<=m-1)
	   {
	   	     if(a[low][high] == val )
	   	     {
	   	     	  found = true;
	   	     	  break;
			 }
			 else
			 if( a[low][high] > val)
			 {
			 	   // value will be in left side 
			 	   high-=1;
			 }
			 else
			 {
			 	   low+=1;
			 	   
			 }
			 
	   }
	   
	   if(found)
	   {
	   	  cout<<"Found"<<endl;
	   }
	   else
	   {  
	      cout<<"Not Found"<<endl;
	   }
}
 
 


int main()
{
	 cin>>n>>m;
	 
	 for(int i=0;i<n;++i)
	 {
	 	  for(int j=0;j<m;++j)
	 	  {
	 	  	 cin>>a[i][j];
		  }
	 }
	 
	 int x;
	 cin>>x;
	 
	 //method1(x);
	 
	// method2(x);
	
	//method3(x);
	
	variant2(x);
	
	 
	 
	
}


