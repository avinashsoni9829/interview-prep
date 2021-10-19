class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0) return 0 ;
        
        int ans = INT_MAX;
        
        vector<int>pre(n+1,0);
        
        for(int i = 1 ; i <= n ; ++i)
        {
           pre[i] = pre[i-1] + nums[i-1];  
        }
        
        for(int i = 1; i <= n ; ++i)
        {
           int v = target + pre[i-1];
           auto lb = lower_bound(pre.begin(),pre.end(),v);
        
           if(lb!=pre.end())
           {
             ans = min(ans,static_cast<int>(lb-(pre.begin() + i - 1))); 
           }
        }
        
        return  (ans!=INT_MAX) ? ans : 0;
        
        
    }
};	
