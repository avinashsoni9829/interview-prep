class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
     
        priority_queue<pair<int,int>, vector< pair<int,int>>, greater<pair<int,int>>>pq;
        
        
        int sum = 0;
        int ans = INT_MAX;
        auto n =  nums.size();
        
        for(int i = 0 ; i < n  ; ++i){
            
            sum = sum + nums[i];
            
            if(sum >= k){
                  ans = min(ans , i + 1);
            }
            
            while(pq.size() and sum - pq.top().first >= k){
                  auto &t = pq.top();
                  ans = min(ans , i - t.second);
                  pq.pop();
            }
            
            pq.push({sum , i});
        }
        
        if(ans == INT_MAX) return  -1;
        
        return ans;
        
        
        
    }
};
