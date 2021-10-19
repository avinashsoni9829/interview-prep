#include<bits/stdc++.h>
using namespace std;

 /*
 
   flow of ans :
   
   1) insertion sort appraoch
   
   2) 3 pointer approach 
 
 
 */ 





/*

     insertion sort based approach 
     
     

                                   *     j=n-1         arr1
                                     
                                       
                                       i=m-1        arr2 
  
  
    loop from i=m-1 to 0
    
    init last=a[n-1]
    
    for(int j=n-2; j>=0 and a[j]>b[i] ; j--)
    {
       
	    a[j+1]=a[j];         
    
    }
    
    
    if(j!=m-2 or last>b[i])
    {
      
	  a[j+1]=b[i];
	  b[i]=last;
	  
	     
 }


  # why last>a[i] as a condition ?
  
  suppose no elements are shifted so in that case we can just check if the last element is greater than the value
  if it is then it need to be shifted in the other half 
  thats why last >a[i]  is neccessary
  


*/


/* 
   
   
   
   time  : O( m * n ) worst case occurs when all elements of ar1[] are greater than all elements of ar2[]  
   
   space  : O(1)
 
 
 
 */

    void method1(vector<int>&a,vector<int>&b,int n,int m){
	
	
	for(int i=m-1;i>=0;--i){
		
		int last=a[n-1];
		int j;
		for( j=n-2;j>=0 and a[j]>b[i];j--){
			a[j+1]=a[j];
		}
		
		if(j!=n-2 || last>a[i]){
			
			a[j+1]=b[i];
			b[i]=last;
	    }
	}
	
	
}
 


/*

   optimized approach : 
   
   
   1) Initialize i,j,k as 0,0,n-1 where n is size of arr1 
   
   2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively
     if arr1[i] is less than arr2[j]
        increment i
     else
        swap the arr2[j] and arr1[k]
        increment j and decrement k

3) Sort both arr1 and arr2 



   time : O((n+m) log(n+m))
   
   space : O(1)

*/


void method2(vector<int>&a,vector<int>&b,int n,int m){
	
	int i=0,j=0,k=n-1;
	
	while(i<=k and j<m){
		if(a[i]<b[j]){
			i+=1;
		}
		else
		{
			   swap(b[j],a[k]);
			   k-=1;
			   j+=1;
		}
	}
	
	
	sort(a.begin(),a.end());
	
	sort(b.begin(),b.end());
	
	
}




int main()
{
  
       int n,m;
       cin>>n>>m;
       vector<int>a(n),b(m);
       
       for(auto &z:a) cin>>z;
       
	   for(auto &z:b) cin>>z;
       	
	   
	   //method1(a,b,n,m); 
	  
	   
	   method2(a,b,n,m);
	  
	     for(int i=0;i<n;++i)
	   cout<<a[i]<<" ";
	   
	   for(int i=0;i<m;++i)
	   	cout<<b[i]<<" ";
}


