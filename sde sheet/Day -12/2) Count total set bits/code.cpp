#include<bits/stdc++.h>
using namespace std;


/*
  count for each value
*/


int setbits(int n)
{
	   int count = 0 ;
	   
	   for(int i = 0 ; i < 8 * sizeof(int) ; ++i)
	   {
	   	    count = count + (n&(1<<i));
	   }
	   
	   return count;
	   
}

int setbits2(int n)
{
	  int count  = 0 ;
	  
	  while(n)
	  {
	  	  count = count + (n&1);
	  	  n = n >> 1;
	  }
	  return count;
}

int setbits3(int n)
{
	   int count = 0 ;
	   while(n)
	   {
	   	  n = n & (n-1);
	   	  count = count + 1;
	   }
	   
	   return count;
}


/*

time  : o(nlogn)
space : o(1)

now method 1 starts
*/


int method1(int n)
{
	 int ans = 0 ;
	  for(int i = 1 ; i <= n ; ++i)
	  { 
	  
	     ans = ans + setbits3(i);
	  }
	  
	  return ans;
}

/*
  method 2: 
  observation based
  
  time : O(logn)


*/


int largestpow2(int n)
{
	  int ans = 0;
	  
	  while((1<<ans) <= n)
	  {
	  	 ans = ans + 1;
	  }
	  return ans - 1;
}
int method2(int n)
{
	
	 if(n<=1) return n;
	 
	 int x = largestpow2(n);
	 
	 return x * (1<<(x-1)) + ( n - (1<<x) + 1) + method2(n-(1<<x));
	 
	
}



int main()
{
	  int n;
	  cin>>n;
	  
	  //cout<<method1(n)<<endl;
	  
	  cout<<method2(n)<<endl;
	  
}
