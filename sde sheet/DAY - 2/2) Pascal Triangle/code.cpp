#include<bits/stdc++.h>
using namespace std;
#define ll long long int

/* 

 Pascal triangle  
 
  ncr  = n!/ (n-r)! r!

*/

/** type 1 :  printing the pascal triangle **/

   /*    ******************************************* Method 1 **************************** 
         
		  time complexity  : O(n * n * n)
   
   
     */  

ll binomialCoeff(ll n,ll r)
{
	   ll ans=1;
	   
	   if(r>n-r)
	   {
	   	  r=n-r;
	   }
	   
	   for(ll i=0;i<r;++i)
	   {
	   	  ans*=(n-i);
	   	  ans/=(i+1);
	   	  
	   }
	   
	   return ans;
}

void method1(int n)
{
  	    for(int len=0;len<=n;++len)
  	    {
  	    	   
		   for(int i=0;i<=len;++i)
	       {
	       	   cout<<binomialCoeff(len,i)<<" ";
		   }
		   
		   cout<<endl;
		   
		
		}
}





/*     * *************   method 2 *************************************** 

      
      time  :  O(n * n)
      space : O( n * n)
      
      
        
     
*/

void method2(int n)
{
	 ll dp[n+1][n+1];
	 
	 for(int len=0;len<=n;++len)
	 { 
	    for(int i=0;i<=len;++i)
		{
		    
			  if(i==0 or i==len)
		      {
		      	   dp[len][i]=1;
		      	   
			  }
			  else
			  {
			  	   dp[len][i] = dp[len-1][i] + dp[len-1][i-1];
			  }
			  
			  cout<<dp[len][i]<<" ";
	       
		}
		cout<<endl;
		    	   
	 }
}

/********************************************** method 3 ******************************************************

    time  :   O ( n * n ) 
    space :   O ( 1 )
      


*/

void method3(int n)
{
for (int line = 1; line <= n; line++)
{
    int C = 1; 
    for (int i = 1; i <= line; i++)
    {
    printf("%d ", C); // The first value in a line is always 1
    C = C * (line - i) / i;
    }
    printf("\n");
}

}

int main()
{ 

   ll n;
   cin>>n;
   
     //method1(n);
     //method2(n);
       method3(n);
       
    
 

}


