#include<bits/stdc++.h>
using namespace std;


/*  Method 1  brute force  time  :  O(n * n * n  * log n )   
   
                           space : O(m) { no of unique triplets }
 
 */

void method1(vector<int>a,int n )
{
	   set<vector<int>>ans;
	   
	   for(int i = 0  ; i < n ; ++i)
	   {
	   	   for(int  j = i  + 1 ; j < n ; ++j)
	   	   {
	   	   	   
		     for(int  k = j + 1 ; k < n ; ++k)
			 {
			      int x = a[i];
				  int y = a[j];
				  int z = a[k];
				  
				  if(x + y + z == 0 )
				  {
				  	 vector<int>temp;
				  	 temp.push_back(x);
				  	 temp.push_back(y);
				  	 temp.push_back(z);
				  	 sort(temp.begin(),temp.end());
				  	 
				     ans.insert(temp);	  
				  }	  
				   
			 }	  
		   }
	   }
	   
	   for(auto z:ans)
	   {
	   	  for(auto u : z)
	   	  {
	   	  	   cout<<u<<" ";
			 }
			 
			 cout<<endl;
	   }
}

/* 
   Method 2  Using Hashing  
                            time  :  O(n * n   * log n )   
   
                           space : O(m + n) { no of unique triplets }
 
 */
 
 
 void method2(vector<int>a,int n)
 {
 	set<vector<int>>ans;
 	
 	map<int,int>mp;
 	
 	for(auto z:a) mp[z]++;
 	
 	for(int i = 0 ; i < n ; ++i)
 	{
 		 mp[a[i]]-=1;
 		 
 		  for(int  j = i+1 ; j < n ; ++j)
 		  {
 		  	   mp[a[j]]-=1;
 		  	   
 		  	   int curr_sum = a[i] + a[j];
 		  	   int rem = 0 - curr_sum;
 		  	   
 		  	   if(mp[rem]>0)
 		  	   {
 		  	       vector<int>temp;
					  temp.push_back(a[i]);	  
					  temp.push_back(a[j]);	  
					  temp.push_back(rem);
					  sort(temp.begin(),temp.end());
					  ans.insert(temp);
					  	  
			   }
			  
 		       mp[a[j]]+=1;
		   }
		   
		   mp[a[i]]+=1;
		   
		   	
	}
	
	 for(auto z:ans)
 {
 	  for(auto k : z)
 	  {
 	  	  
	      cout<<k<<" "; 
	  }
	  
	  cout<<endl;
 }

	

 }
 
 
 
/* 
   Method 3 Using Two Pointer Technique   
                            time  :  O(n * n   * log n )   
   
                           space : O(m + n) { no of unique triplets }
 
 */
 
 
 class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};

int main()
{
       int n ;
       cin>>n;
       
       vector<int>a(n);
       
       for(auto &z:a) cin>>z;
       
      // method1(a,n);
      
      //method2(a,n);
      method3(a,n);
      
       
}


