
/*
   Kadane's Algo based 

 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int>mp;
        
        int curr_sum = 0 ;
        int ans= 0;
        
        for(int i = 0 ; i < n ; ++i){
           
          curr_sum = curr_sum + nums[i];
            if(curr_sum == k){
                 ans = ans + 1;
                 
            }
          if(mp.find(curr_sum - k )!=mp.end()){
               ans = ans + mp[curr_sum - k ];   
          }
            
         mp[curr_sum]++;
        
        }
        
        return ans;
        
        
    }
};
