#include<bits/stdc++.h>
using namespace std;

int method2(int n )
{ 

  int ans = 0;
  
  // count no of iterations to react x = 0;
  
  while(n!=0){
  	n = (n & (n<<1));
  	ans = ans + 1;
  }
  
  return ans;
  
    
    
            
}


int main()
{
   int  n ;
   cin>>n;
   
   cout<<method2(n)<<endl;          
}
