#include<bits/stdc++.h>
using namespace std;

/* 
    longest substring having distinct characters  
    
*/

/*

 flow of ans  : 
 
  1) brute force    O( n * n * n)   +  O(n)
  2) using sliding wndow O( n * n ) + o(n)
  3) using hashing  O(n) + O(n)




*/

/*------------------------- METHOD 1------------------------------*/
/*
   brute force 
   time :  O(n^3)
   space:  O(n)

*/

bool f(string s,int l,int r)
{
	   set<char>st;
	   
	   for(int i = l ; i <= r; ++i)
	   {
	   	     if(st.find(s[i])!=st.end())
	   	     {
	   	     
				 return false;	 
			   	
			 }
			 else
			 {
			 	 st.insert(s[i]);
			 }
	   }
	   
	   return true;
}


int method1(string s,int n)
{
	  int ans = 0;
	  for(int i = 0 ;i<n; ++i)
	  {
	  	 for(int  j = i ; j<n; ++j)
	  	 {
	  	 	  
		      if(f(s,i,j))
		      {
			    ans = max(ans,j-i+1);
			  }
		}
	  }
	  
	  return ans;
	  
}

/*------------------------- METHOD 1------------------------------*/
/*  
    using sliding window 
	
	time :  O ( n * n )
	space:  O(n) 

*/

int method2(string s,int n)
{
   
    int res = 0; // result
 
    for (int i = 0; i < n; i++){
         
        // Note : Default values in visited are false
        vector<bool>visited(256);  
 
        for (int j = i; j < n; j++) {
 
            // If current character is visited
            // Break the loop
            if (visited[s[j]] == true)
                break;
 
            // Else update the result if
            // this window is larger, and mark
            // current character as visited.
            else {
                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
        }
 
        // Remove the first character of previous
        // window
        visited[s[i]] = false;
    }
    return res;
}


/*   hashing method */

/*  time : O(n)
    space : O(n)
    */
    
 int method3(string s,int n )
 {
    vector<int>last_occur(256,-1);
    int ans = 0 ;
    int curr = 0 ;
    
    for(int i = 0 ; i < n ;  ++i)
    {
       curr = max(curr,last_occur[s[i]] + 1);
       ans = max(ans, i - curr + 1);
       last_occur[s[i]] = i;
       
	   	  
	}
	
	return ans;
	
	
		
 }   
 
 
 int method4(string s, int n ){
 	  map<char,int>mp;
 	  
 	  int i = -1; 
 	  int j = -1;
 	  int ans = 0 ;
 	  
 	  while(true){
 	  
	      bool flag1 = false;
		  bool flag2 = false;
		  
		  while(i<n-1){
		  	  flag1 = true;
		  	
		  	i = i + 1;
		  	
		  	mp[s[i]]++;
		  	
		  	if(mp[s[i]] == 2){
		  		 break;
			  }
			  else
			  {
			  	 ans = max(ans, i - j );
			  }
		  }
		  
		  while(j<i){
		  	 flag2 = true;
		  	 
		  	 j = j + 1;
		  	 
		  	 mp[s[j]]--;
		  	 
		  	 if(mp[s[j]] == 1){
		  	 	  break;
			   }
		  }
		  
		  if(flag1 == false and flag2 == false)
		  {
		  	 break;
		  }
		  
		  
		  	 
	   }
	   
	   
	   return ans;
	   
	   
	   
 	  
 }



int main()
{
  
  int n;
  cin>>n;
  
  string s;
  cin>>s;
  
  cout<<method4(s,n)<<endl;
  
  
}


