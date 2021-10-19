#include<bits/stdc++.h>
using namespace std;

/* Majority Element  (  >  N/3 ) elements   */

/*

Flow of ans  : 

  1)  brute force     O(n * n ) ,  O(1)
  
  2) Map     O(n) or  O(nlogn)   ,  O(n)
  
  3)  Booye Moore Algo   O(n)  + O(1)

*/


/*

  Method 1
  
  time : O(n * n )
  
  space : O(1)


*/


void method1(vector<int>a,int n)
{
	 set<int>ans;
	 
	 for(int i=0;i<n;++i)
	 {
	 	   int curr_v = a[i];
	 	   int curr_cnt = 0;
	 	   
	 	   for(int j=0;j<n;++j)
	 	   {
	 	       curr_cnt = curr_cnt + (a[j] == curr_v);	   
		   }
		   
		   if(curr_cnt > n/3)
		   {
		   	   ans.insert(curr_v);
		   }
	 }
	 
	 for(auto z:ans)
	 {
	 	  cout<<z<<" ";
	 }
	 
	 cout<<endl;
	 
}


/*
   using map O(n) | O(n logn)
   
   space  : O(n)

*/
void method2(vector<int>a,int n )
{
	  map<int,int>mp;
	  
	  for(auto z:a)
	  {
	  	  mp[z]++;
	  }
	  
	  set<int>ans;
	  
	  for(auto z:mp)
	  {
	  	  if(z.second > n/3)
	  	  {
	  	     ans.insert(z.first);	  
		  }
	  }
	  
	  for(auto z:ans)
	  {
	  	  cout<<z<<" ";
	  }
	  
	  cout<<endl;
	  
	  
}




/*
    using booye moore voting algorithm
    
    time : O(n)
    
    space : O(1)

*/


void method3(vector<int>a,int n)
{
	   set<int>ans;
	   
	   
	   int num1=-1,num2=-1,cnt1=0,cnt2=0;
	   
	   for(int i = 0; i < n ; i++ )
	   {
	   	   if(a[i] == num1)
	   	   {  
		       cnt1 ++;
		   }
		   else
		   if(a[i] == num2)
		   {
		   	   cnt2 ++;
		   	   
		   }
		   else
		   if(cnt1 == 0)
		   {
		   	  num1 = a[i];
		   	  cnt1 ++;
		   }
		   else
		   if(cnt2 == 0)
		   {
		   	  num2 = a[i];
		   	  cnt2++;
		   }
		   else
		   {
		   	  cnt1 -- ;
		   	  cnt2 -- ;
		   }
	   }
	   
	   cnt1 = 0;
	   cnt2 = 0;
	   
	   for( int  i = 0 ; i < n ; i++)
	   {
	   	   cnt1 = cnt1 + (a[i] == num1);
	   	   cnt2 = cnt2 + (a[i] == num2);
	   }
	   
	   if(cnt1 > n / 3)
	   {
	   	  ans.insert( cnt1 );
	   	  
	   }
	   
	   if(cnt2 > n / 3)
	   {
	   	 ans.insert( cnt2 );
	   }
	   
	   
	   for(auto z: ans)
	   {
	   	  cout<<z<<" ";
	   }
	   
	   cout<<endl;
	   
}


int main()
{
	int n;
	cin>>n;
	
	vector<int>a(n);
	
	for(auto &z:a ) cin>>z;
	
	method1(a,n);
	
	 


}


