#include<bits/stdc++.h>
using namespace std;

/* 

   longest Subarray with sum  0

*/

int method(vector<int>A,int n)
{
	  
    int sum = 0 ;
    map<int,int>mp;
    int ans = 0;
    
    for(int  i = 0; i <  n; ++i)
    {
        
        sum = sum + A[i];
        
        if(sum==0)
        {
             ans = i + 1;
        }
        else
        {
             if(mp.find(sum)!=mp.end())
             {
                  ans = max(ans,  i - mp[sum]);
             }
             else
             {
                  mp[sum] =  i ;
             }
        }
         
        
    }
    
    return ans;
}

int main()
{
     int n;
     cin>>n;
     vector<int>a(n);
     for(auto &z:a) cin>>z;
     
     cout<<method(a,n)<<endl;
     
}


