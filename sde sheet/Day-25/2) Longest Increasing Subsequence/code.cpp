/* Longest Increasing subsequence*/

#include<bits/stdc++.h>
using namespace std;


/*
   time : exponential
   space : O(1)

*/

int lisRecur(vector<int>a,int n){
	     
	   if(n==1) return 1;
	   
	   int curr_max = 1 , o_max = 0;
	   
	   for(int  i = 1 ; i<n ; ++i){
	   	  
	   	  // finding the LIS so far 
	   	   int temp = lisRecur(a,i);
	   	   
	   	   if(a[i-1] < a[n-1]){
	   	     
	   	      if(temp + 1 > curr_max){
	   	      	 curr_max = temp + 1;
				 }
			   	  
		   }
	   	   
	   }
	   
	   o_max = max(o_max ,curr_max);
	   
	   
	   return o_max ;
	
}


/*
 Dp tabulation 
 
 time : O(n * n)
 space : O( n * n)

*/

int lisDp(vector<int>a,int n){
	 int dp[n];
	 dp[0] = 1;
	 
	 for(int  i = 1 ; i < n ; ++i){
	 	   
	 	   dp[i] = 1;
	 	   
	 	   for(int j = 0 ; j < i ; ++j){
	 	   	   if(a[i] > a[j]){
	 	   	       if(dp[i] < dp[j] + 1){
	 	   	       	  
				     dp[i] = dp[j] + 1;
				  
				  }	   
			   
			   }
			}
	 }
	 
	 
	 return *max_element(dp,dp+n);
	 
	 
}


/*

   method 3 : make a copy and sort the array and then find the LCS b/w original array and new sorted array
   
   time : O(n * log n)
   space : O(n)
   

*/

   int nextGreater(int dp[],int low,int high,int v){
          while(low < high){
                  int mid = low + (high - low) / 2;
                  
                  if(dp[mid] >=v){
                        high =  mid;
                  }
                  else
                  {
                        low = mid + 1;
                  }
          }
          
          return high;
          
    }
    
    
    int longestSubsequence(int n, int a[])
    {   
          int ans = 1;
          
          int dp[n];
          
          dp[0] = a[0];
          
          for(int  i =  1; i < n ;++i){
                if(a[i] > dp[ans-1]){
                      dp[ans] = a[i];
                      ans = ans + 1;
                }
                else
                {
                      int nxt = nextGreater(dp,0,ans-1,a[i]);
                      dp[nxt] = a[i];
                }
          }
          
          return ans;
          
      
    }



/*

Printing the LIS

*/

void printLIS(vector<int>arr,int n){
	  // L[i] - The longest increasing sub-sequence
    // ends with arr[i]
    vector<vector<int> > L(n);
 
    // L[0] is equal to arr[0]
    L[0].push_back(arr[0]);
 
    // start from index 1
    for (int i = 1; i < n; i++)
    {
        // do for every j less than i
        for (int j = 0; j < i; j++)
        {
            /* L[i] = {Max(L[j])} + arr[i]
            where j < i and arr[j] < arr[i] */
            if ((arr[i] > arr[j]) &&
                    (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }
 
        // L[i] ends with arr[i]
        L[i].push_back(arr[i]);
    }
 
    // L[i] now stores increasing sub-sequence of
    // arr[0..i] that ends with arr[i]
    vector<int> max = L[0];
 
    // LIS will be max of all increasing sub-
    // sequences of arr
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;
            
   for(auto z:max){
   	cout<<z<<" ";
   }
   
   cout<<endl;
   
 
	 
}



int main(){
	  int n ; 
	  cin>>n;
	  
	  vector<int>a(n);
	  
	  for(auto  &z : a){
	  	  cin>>z;
	  }
	  

	  
	  
	  //cout<<lisRecur(a,n)<<endl;
	  
	  cout<<lisDp(a,n)<<endl;
	  
	  	  printLIS(a,n);
	  
} 
