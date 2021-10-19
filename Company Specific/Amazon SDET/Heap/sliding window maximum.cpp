//sliding window maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n  = nums.size();
        // build a max heap  
        
        priority_queue<pair<int,int>>pq;
        
        vector<int>ans;
        
        for(int  i = 0 ; i < n ; ++i){
            
            while(!pq.empty() and pq.top().second <= (i-k)){
                
                pq.pop();
            }
            
            pq.push(make_pair(nums[i], i));
            
            if(i>=k-1){
                ans.push_back(pq.top().first);
            }
        }
        
        return ans;
        
    }
};
