#include<bits/stdc++.h>
using namespace std;

// Two Sum 
/*
  flow 
    1)  brute force 
    
	2) Hashing (map approach ) 
    
    3) using two pointer + Pairs + compartor function  (use structure if pair is not allowed ) 
     

*/


 /* ---------------------------------------  Method 1------------------------------------------------------------------- */
 
 /*
    time : O(n * n)
    space  : O(1)
 
 */
 
  
  void method1(vector<int>a,int target)
  {
  	   int n = a.size();
  	   
  	   vector<int>ans;
  	   
  	   for(int i=0;i<n;++i)
  	   {
  	      for(int j=0;j<m;++j)
		  {
			 if(a[i] + a[j]==target and i!=j)
			 {
			    ans.push_back(i);
				ans.push_back(j);
				break;	  
			 }	  
		     
		  }	  
	   }
	   
	   for(auto z:ans)
	   {
	   	 cout<<z<<" ";
	   }
	   cout<<endl;
	   
  	   
  }





/* ---------------------------------------  Method 2------------------------------------------------------------------- */
 
 /*
 
    time : O(n)
    space : O(n)
 
 */
 
 void method2(vector<int>nums,int target)
 {
 	  vector<int>ans;
        
        int n = nums.size();
        
        
        map<int,int>last;
        
        for(int  i = 0 ; i <  n ; ++i)
        {
          
             if(last.find(target - nums[i]) != last.end())
             { 
                 ans.push_back(last[target - nums[i]]);
                 ans.push_back(i);
                 
                break;
             }
             
             last[nums[i]] = i;
             
        }
        
        
        for(auto z:ans)
        {
        	 cout<<z<<" ";
		}
 }
 
 /* ---------------------------------------  Method 3------------------------------------------------------------------- */
  
   /*
 
    time : O(n)
    space : O(n)
 
 */
 
   
  bool comp(pair<int,int>&a,pair<int,int>&b)
    {
       return a.first<b.first;   
    }
    
	
	void method3(vector<int>& nums, int target) {
        vector<int>ans;
        
        int n = nums.size();
        
        vector<pair<int,int>>p(n);
        
        for(int i = 0 ;i<nums.size(); ++i)
        {
             p[i].first = nums[i];
             p[i].second = i;
        }
        
        sort(p.begin(),p.end(),comp);
        
        int low = 0 , high = n - 1;
        
        while( low  < high )
        {
          
            if(p[low].first + p[high].first == target)
            {
                ans.push_back((int)p[low].second);
                ans.push_back((int)p[high].second);
                break;
            }
            else
                if(p[low].first + p[high].first > target)
                {
                      high = high - 1;
                }
             else
             {
                    low = low + 1;    
              }
            
        }
        
         for(auto z:ans)
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
	
	for(auto z:a) cin>>z;
	
	int target ;
	
	cin>>target;
	 
}


