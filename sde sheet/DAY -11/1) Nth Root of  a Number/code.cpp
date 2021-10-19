#include<bits/stdc++.h>

using namespace std;

/*
   time complexity
   
   p * log( n * (10 ^ d))
   d = decimal accuracy
   p = pth root of number n

*/

/*  Nth Square root */
double mul(double d,int n)
{
	 double ans = 1 ;
	 for(int i = 0 ; i < n ; ++i)
	 {
	 	  ans  = ans * d ;
	 } 
	 
	 return ans;
}
double eps = 1e-6;

int main()
{
	int n;
	 double d;
	 cin>>d>>n;
	 
	 double low = 1  , high = d;
	 double mid;
	 while(high - low > eps)
	 {
	     mid = (low + high) / 2;
		
		if(mul(mid,n) < d)
		{
		    low = mid;	 
		}
		else
		{
		    high = mid;	 
		}	 
	  
	 } 
	 
	 cout<<setprecision(10)<<low<<" "<<high<<endl;
	 
	 
}


