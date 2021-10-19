
// Problem: Total Components
// Contest: CodeChef - May Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME96B/problems/NUMCOMP1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)



#include<bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << "=" << a << ' '<<endl;
#define ll int64_t
#define all(x)  x.begin(),x.end()
const ll modu=1e9+7;

const int MAX=1e7;

int prefix[MAX + 1];

void pre()
{
    
    bool prime[MAX + 1];
   
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= MAX; p++) {
 
        if (prime[p] == true) {
 
            // 
            for (int i = p * 2; i <= MAX; i += p)
                prime[i] = false;
        }
    }
 
   
    prefix[0] = prefix[1] = 0;
    for (int p = 2; p <= MAX; p++) {
        prefix[p] = prefix[p - 1];
        if (prime[p])
            prefix[p]++;
    }
}
 
int f(int L, int R)
{
    return prefix[R] - prefix[L];
}


int main()
{ 
   pre();
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
  
  
  int t;
  cin>>t;
  while(t--)
  {
  	   int n;
  	   cin>>n;
  	   
  	   if(n==2)
  	   {
  	   	 cout<<1<<endl;
  	   }
  	   else
  	   if(n==3)
  	   { 
  	  
  	     cout<<2<<endl;
  	    }
  	    else
  	   
  	   cout<<f(n/2,n)+1<<endl;
  	   
  	
  	   
  }
    
}

