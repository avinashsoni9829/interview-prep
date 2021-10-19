#include<bits/stdc++.h>
using namespace std;

// find duplicate in the array


/* -----------------------------------SORTING METHOD ------------------------------------*/

/*   O(nlogn) + O(1)               */


void merge(vector<int>&a,int low,int mid,int high)
{
	     // create two subarrays 
	     
	     int n1=mid-low+1;
	     int n2=high-mid;
	     
	     int L[n1],R[n2];
	     
	     
	     for(int i=0;i<n1;++i)
	     {
	     	  L[i]=a[low+i];
	     	  
		 }
		 
		 for(int i=0;i<n2;++i)
		 {
		 	   R[i]=a[mid+1+i];
		 }
		 
		 int i=0,j=0,k=low;
		 
		 while(i<n1 and j<n2)
		 {   
		     if(a[i]<a[j])
		     {
		     	  a[k]=L[i];
		     	  i+=1;
			 }
			 else
			 {
			 	  a[k]=R[j];
			 	  j+=1;
			 }
			 k+=1;
	     }
	     
	     while(i<n1)
	     {
	     	 a[k]=L[i];
	     	 i+=1;
	     	 k+=1;
		 }
		 while(j<n2)
		 {
		 	  a[k]=R[j];
		 	  j+=1;
		 	  k+=1;
		 }
}




void helper(vector<int>&a,int low,int high)
{
	   if(low<high)
	   {
	   	      int mid=(low+high)/2;
	   	      
	   	      helper(a,low,mid);
	   	      helper(a,mid+1,high);
	   	      merge(a,low,mid,high);
	   	      
	   	      
	   }
}



void MergeSort(vector<int>&a)
{
	int low=0,high=a.size()-1;
	
	helper(a,low,high);
	
}






int method1(vector<int>&a)
{
	 int n=a.size();
	 
	 MergeSort(a);
	 
     for(int i=0;i<n-1;++i)
	 {
	 	  if(a[i]==a[i+1])
	 	  {
	 	     return a[i]; 	  
		  }
	 }
	 
	 return -1;
	 
	    
}



/* -----------------------------------MAP METHOD ------------------------------------*/

/*   O(n)  + O(N) extra space                                 */


int method2(vector<int>&a)
{
	 int ans=0;
	   map<int,int>mp;
	   for(auto z:a) mp[z]++;
	   
	   for(auto z:mp)
	   {
	   	  if(z.second==2)
	   	  {
	   	      ans=z.first;
			  break;	 
		  }
	   }
	   
	   return ans;
	   
}

/*     --------------------------------  using modulo method (method 3) ---------------------------------- */ \

/*
  
   first add n to all numbers 
   take modulo a[i] %n for the idx
   
   
   now after this we have a new array in which one value will be greater than > 2 * n as some repeted value is there
   
   so find the idex at which that occurs and restore the array

  time  : O(n)
  space : O(1)


*/



int method3(vector<int>&a)
{
	   int n=a.size();
	   int ans=0;
	   int mxf=-1;
	   for(int i=0;i<n;++i)
	   {
	   	 a[(a[i]%n)]+=n;
	   }
	   
	   for(int i=0;i<n;++i)
	   {
	   	  if(a[i]>mxf)
	   	  {
	   	      mxf=a[i];
			   ans=i;	 	  
		  }
		  a[i]%=n;
		  
	   }
	   
	   return ans;
	   
}

/*--------------------------------------------- Floyd's Cycle Detection Algo -------------------------------- */


/*


  Explaination Of the algorithm  : 
  
    
   fast moves 2 points 
   slow moves 1 points 
   
   when then collide let the distance b/w starting node and first point of collission be   a 
   
   and the distance between first node and the second node be  x  ( second node is in the cycle  ) 
   
   now slow pointer covers  
   
   
   the duplicate node is a cycle enterance 
   
   2 * d(fast) = d(slow)
   
   meeting point at a 
   2 * (x+a) = x+nc+a
   
   x+a=nc
   
   now fast moves x
   slow moves a-x
   so total a-x +  x =a;
   
   
    

*/ 

int method4(vector<int>nums) {
      
         int slow=nums[0];
         int fast=nums[0];
         
         // for detecting loop
         do
         {
             slow=nums[slow];
             fast=nums[nums[fast]];
         }
         while(slow!=fast);
         
         // for the final phase where the fast pointer moves  x + a distance and slow moves c-a distance at same pace 
         fast=nums[0];
         
         while(slow!=fast)
         {
             slow=nums[slow];
             fast=nums[fast];
         }
         return slow;
      
     }


int main()
{
   
   int n;
   cin>>n;
   
   vector<int>a(n);
   for(auto &z:a) cin>>z;
   
//   cout<<method1(a)<<endl;
 //  cout<<method2(a)<<endl;
     //cout<<method3(a)<<endl;
	 cout<<method4(a)<<endl;    // numbers should be in range 1 to N
	 	 
	 
}


