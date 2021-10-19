#include<bits/stdc++.h>
using namespace std;


/*
   method 1  :  brute force method 
       time  :  O( n * n )
       space :  O(1)

*/


void method1(vector<int>a,int n)
{
	    //  ans  =  ans +  min ( leftmax[i] , rightmax [i] )  -a[i];
	    
	    
	           int ans = 0 ;
	    	   
	    	   
	    for(int i = 1; i < n-1;++i)
	    {
	    	int right_max =a[i];
	    	   int left_max = a[i];
	    
	    	   for(int u = 0 ; u < i ; ++u)
	    	   left_max = max(left_max,a[u]);
	    	   
	    	   for(int v = i + 1 ; v<n;++v)
	    	   {
	    	   	  right_max = max(right_max,a[v]) ;
	    	   	  
			   }
			   
			   ans = ans + min(left_max,right_max) - a[i];
		}
		
		cout<<" ans : " <<ans <<endl;
		
}


/*
   method 2  :  using prefix of max and min 
       
	   time  :  O(3 * n)
	    
       space :  O(2 * n)

*/


void method2(vector<int>a,int n)
{
	   int left[n];
	   int right[n];
	   
	   int ans= 0 ;
	   
	   left[0] = a[0];
	   
	   for(int i = 1 ; i < n ; ++i)
	   {
	   	   left[i] = max(left[i-1],a[i]);
	   	   
	   	   
	   }
	   
	   right[n-1] = a[n-1];
	   
	   for(int i = n - 2 ; i >= 0 ; --i)
	   {
	   	   right[i] = max(right[i+1],a[i]);
	   	   
	   }
	   
	   
	   for(int i = 0 ; i < n ; ++i)
	   {
	   	   ans = ans + min(left[i],right[i]) - a[i];
	   }
	   
	   
	   cout<<"Ans : "<<ans<<endl;
	   
	   
}


/*
    using two pointer technique 
    method 3 :  time : O(n)
                space : O(1)
*/

class Solution {
public:
    int trap(vector<int>& a) {
        int n =a.size();
        
        int ans = 0 ;
        
        int lmax = 0 , rmax = 0 ;
        int low = 0 ;
        int high  = n - 1;
        
        while(low <= high)
        {
         
             if(a[low]<=a[high])
             {
                 lmax = max(lmax,a[low]);
                 ans = ans  + lmax - a[low];
                 low = low + 1;
             }
             else
             {
               rmax = max(rmax,a[high]);
                 ans = ans  + rmax - a[high];
                 high = high - 1;
                
             }
             
             
        }
        
        return ans;
        
    }
};



int main()
{
  int n;
  cin>>n;
  
  vector<int>a(n);
  for(auto &z:a) cin>>z;
  
  
 // method1(a,n);
  method2(a,n);
  
    
  
    
}


