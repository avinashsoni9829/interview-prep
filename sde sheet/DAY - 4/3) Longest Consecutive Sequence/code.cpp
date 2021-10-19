#include<bits/stdc++.h>
using namespace std;
//  longest consecutive sequence

/*
       flow of ans : 
  
       1)  brute force with sorting 
       2)  using set
       3)  using differnce of two values at a time


*/


/* --------------------- Method 1 -----------------------  */

/*
   
    time  : O( n * n )
    space : O(1)

*/

 int method1(vector<int>a,int n)
 {
 	 int ans = 0;
 	 sort(a.begin(),a.end());
 	 
 	for(int i = 0 ;i<n;++i)
    { 
         int idx = i ;
         int len=0;
         int curr = a[idx] - 1;
         while(a[idx] == curr+1)
         {
         	  idx+=1;
         	  curr+=1;
         	  len+=1;
		 }
		 
		 ans = max(ans,len);
 		  
	}
	
	return ans;
	
	
	
 	 
 }
 
 
/* --------------------- Method 2 -----------------------  */

/*
  Using Set 
   time  : O(n)
   space : O(n)

*/

 
 int method2(vector<int>a,int n)
 {
 	   set<int>s;
        
       
       
        
        if(n==0) return 0;
        if(n==1) return 1;
         int ans = 1;
      
        for(auto z:a)
        {
            s.insert(z);
        }
        
        for(int i = 0 ; i<n;++i)
        {
             if(s.count(a[i]-1)!=0)
             {
                  
             }
            else
            {
                int curr = 1;
                int v = a[i];
                while(s.count(v+1)>0)
                {
                  curr = curr + 1;
                  v = v + 1;
                }
                
                ans = max(ans,curr);
                
            }
        
        }
        
        
        
        return ans;
        
 	 
 }
 /* --------------------------  Method 3 ------------------------- */
 /*
   Using Kadane's Algorithm 
   time  : O(n) + O(nlogn) for sorting 
   space : O(1)

*/
 
 
 int method3(vector<int>a,int n)
 {
 	 
        
        if(n==0) return 0;
        
        
        int overall_max = 1 ;
        int curr_max = 1;
        
        sort(a.begin(),a.end());
        
        for(int i = 1 ; i < n; ++i)
        {
            if(a[i]==a[i-1])
            {
                continue;
                
            }
           
            if(a[i] == a[i-1] + 1)
            {
               curr_max = curr_max + 1;  
            }
            else
            {
              overall_max = max(overall_max , curr_max);
              curr_max = 1;
            }
             
        }
        
        overall_max = max(overall_max , curr_max);
        
        return overall_max;
        
 	 
 	 
 	 
 }


int main()
{
	 int n;
	 cin>>n;
	 
	 vector<int>a(n);
	 
	 for(auto &z:a) cin>>z;
	 
	 //cout<<method1(a,n)<<endl;
	 cout<<method3(a,n)<<endl;
	 
	
}


