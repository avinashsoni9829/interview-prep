#include<bits/stdc++.h>
using namespace std;


/*  4 sum */

/*
   using Map for finding first and last occurence of values and then jumping pointers in two pointer approach 

*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin() , nums.end());
        
        map<int,int>first_occur,last_occur;
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(first_occur.find(nums[i]) == first_occur.end())
            {
                   first_occur[nums[i]] = i;
                
            }
            else
            {
                continue;
            }
        }
        
        for(int  i = n - 1; i>=0 ; i--)
        {
           if(last_occur.find(nums[i]) == last_occur.end())
            {
                   last_occur[nums[i]] = i;
                
            }
            else
            {
                continue;
            }
        
        }
        set<vector<int>>ans;
        
        
        for(int  i = 0 ; i < n - 1 ; ++i)
        {
           for(int j  = i+1 ; j < n ; ++j)
           {
            
                int curr = nums[i] + nums[j];
               
                
               
                int low = j + 1 ; 
               
                int high = n-1 ;
               
               while(low<high)
               {
                  
                    if(nums[low] + nums[high] + curr == target) 
                    {
                         vector<int>temp;
                         temp.push_back(nums[low]);
                         temp.push_back(nums[high]);
                         
                         temp.push_back(nums[i]);
                         temp.push_back(nums[j]);
                        
                         ans.insert(temp);
                         temp.clear();
                        
                         low = last_occur[nums[low]] + 1;
                         high = first_occur[nums[high]] - 1;
                     }
                     else  if( nums[low] + nums[high] + curr > target)
                     {
                          high = high - 1;
                     }
                   else
                   {
                         low = low + 1;
                   }
                    
               }
               
               
           }
        }
        
        vector<vector<int>>anss;
        
        for(auto z:ans)
            anss.push_back(z);
        
        
        return anss;
        
        
       
        
    }





int main()
{
	  int n;
	  cin>>n;
	  
	  vector<int>a(n);
	  
	  for(auto &z:a) cin>>z;
	  
	  int target ;
	  
	  cin>>target ;
	  
	 /*
	   func calls here !
	 */
	
}


