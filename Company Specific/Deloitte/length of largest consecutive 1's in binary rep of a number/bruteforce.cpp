#include<bits/stdc++.h>
using namespace std;

int method1(int n )
{  

    string bin;
    long long int  i ;

   for( i = 1 <<30 ; i > 0 ; i>>= 1){
   	if(n&i){
   		bin+="1";
	   }
	   else
	   {
	   	 bin+="0";
	   }
   }
   
   int o_max = INT_MIN;
   int c_max = 0 ;
   
   int x = bin.length();
   
   
   for(int  i = 0  ; i < x ; ++i){
   	  if(bin[i] == '1'){
   	  	 c_max = c_max + 1;
   	   }
   	   else
   	   {
   	       o_max = max(c_max , o_max);
		   c_max = 0;
		   	  
	   }
   }
   
    o_max = max(c_max , o_max);
    
    return o_max;
 
            
}


int main()
{
   int  n ;
   cin>>n;
   
   cout<<method1(n)<<endl;          
}
