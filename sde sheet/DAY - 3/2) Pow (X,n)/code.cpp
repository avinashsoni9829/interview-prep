#include<bits/stdc++.h>
using namespace std;

/*

 Note  :  N can be negative too 
 here we are taking double values 
 
 time complexity  :  O(log n)
 
*/


double expo(double a,int bb)
{
	double ans=1.0;
	long long int b=abs(bb);
	

	    while(b>0)
	    {
	    	
	    	   if(b&1)
	    	   {
	    	   	ans*=a;  
			   }
			   a*=a;
			   
			   b>>=1;
		}
		
		if(bb<0) return (double)(1.0/(double)ans);
		
		return ans; 
		
		
}





int main()
{
   
    double x;
    int n;
    cin>>x>>n;
    
    cout<<expo(x,n)<<endl;
    
    

}


