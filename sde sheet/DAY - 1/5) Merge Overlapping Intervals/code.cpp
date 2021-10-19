#include<bits/stdc++.h>
using namespace std;


/*
  
  
  flow of ans :
  
  1) brute force approach   O(n^2) O(n)
  
  2) Stack  +  sorting    O(nlogn  + n) O(n)
  
  3) optimal merging    O(nlogn + n)  + O(1)


*/

/*   Brute Force Approach  */

/*  ==================================== Method 1============================== */

/*      O(n^2)         */

struct interval
{
	int start, end;
	
}; 

void brute(interval a[],int n)
{ 
    
     for(int i=0;i<n;++i)
     {
     	  for(int j=0;j<n;++j)
     	  {
     	  	    if(j!=i)
     	  	    {
     	  	      
					  interval first=a[i];
					  
					  interval second=a[j];
					  
					  // if overlapping 
					  
					  if(first.end<second.start)
					  {
					     continue;	 
					  }
					  else
					  {
					       	// delete first 
							   
							 // merge it with second    
					     
					  }	  
					  
				   
				}
		   }
	 }
	  
}

/*  sorting with structure  +  stack approach  */

/* ============================= Method 2 ====================================================== */ 

/*   time  : O(nlogn) + O(n)
      O(n) extra space for stack 

*/





bool comp(interval &a,interval &b)
{  
     if(a.start == b.start)
     {
     	  return a.end<b.end;
	 }
	 
	 return a.start<b.start;
     
}







void merge(interval a[],int n)
{
	   if(n<=0) return;
	   
	   sort(a,a+n,comp);
	   
	   stack<interval>s;
	   
	   s.push(a[0]);
	   
	   for(int i=1;i<n;++i)
	   {
	      
		  interval check=s.top();
		  
		  // if it is not overlapping with current interval push it  
		   
		    /*    
			 
			   [ 2,6] 
			   
			[ 7 , 9 ]
			 
			  
			*/
		   //not overalaping condition
		   
		  if(check.end < a[i].start)
		  {  
		      s.push(a[i]);	  
		  }
		  else
		  {
		      check.end=a[i].end;
			  s.pop();
			  s.push(check);	   
		  } 
	  
	   }
	   
	   
	   /*  printing the intervals */ 
	   
	   while(!s.empty())
	   {
	   	   interval curr= s.top();
			  s.pop();
			  
			  cout<<"["<<curr.start<<" "<<curr.end<<"]"<<endl;
	        
	   }	   
	   
	  
}


/*  Optimal Approach     */

/* =================================================== Method 3 =============================================== */ 

/*   O(nlogn)  + O(1)     */




void optimal(interval a[],int n)
{
	   // sorting 
	   sort(a,a+n,comp);
	   int idx=0;
	   
	   for(int i=1;i<n;++i)
	   {
	   	
	   	   // overlapping condiiton
	   	    if(a[idx].end >= a[i].start)
	   	    {
	   	         a[idx].start  =   min(a[idx].start,a[i].start);
				 a[idx].end  =   max(a[idx].end,a[i].end);	  
				
	        }
	        else
	        {  
			  // not overlapping condition
			     idx++;
	             a[idx]=a[i];
	            
			}
			
			
	   }
	   
	   for(int k=0;k<idx+1;++k)
	   {
	   	  cout<<"["<<a[k].start<<" "<<a[k].end<<"]"<<endl;
	   	  
	   }
	   
	  
	
}


int main()
{


   interval arr[]={{2,4},{3,9},{11,19},{13,35}};
    
	//  method 2
    //  merge(arr,4);	
    //  method 3 
	
	optimal(arr,4);
	
	
	


}


