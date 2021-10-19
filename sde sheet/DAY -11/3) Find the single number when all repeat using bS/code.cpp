/*

  basic approach traverse
  xor approach 
  bs approach 
 

*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int a[], int n)
    {
        int low = 0 , high = n  - 1;
        
        int ans = 0 ; 
        
        while(low <= high)
        {
             if(low == high) break;
             
             int mid = (low + high)/2;
             
             if(mid % 2 ==0)
             {
             	 // here mid strike at first of the two pair
                   if(a[mid] == a[mid+1])
                   {
                        low = mid + 2;
                   }
                   else
                   {
                        high = mid;
                   }
                   
             }
             else
             {
             	 // here mid will strike the second of the two pair 
             	 
                  if(a[mid] == a[mid - 1])
                  {
                       low = mid + 1;
                  }
                  else
                  {
                       high = mid - 1;
                  }
                  
             }
             
        }
        
        return a[low];
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends
