class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n = nums.size();
        
       int sum = 0 ;
        
        for(int i = 0 ; i < n ; ++i){
        sum = (sum + nums[i])%p;
        }
        
        if(sum ==0) return 0;
        
        
        map<int,int>last;
        last[0] = -1;
        
        int curr = 0 ;
        
        int ans = n ;
        
        for(int i = 0 ; i < n ; ++i){
        curr = (curr + nums[i])%p;
        int tmp = (curr - sum)%p;
            if(tmp <0){
                tmp = tmp + p;
            }
            
            if(last.count(tmp)){
             ans = min(ans, i - last[tmp]);    
            }
            
           last[curr] = i;
        }
      
        return ans == n ? -1 : ans;
        
        
        
    }
};
