// double linked list approach 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>>dll;
        
        vector<int>ans;
        
        for(int i = 0 ; i  <  n ;  ++i){
             if(!dll.empty() and dll.front().second <= (i-k)){
                 dll.pop_front();
             }
            
            while(!dll.empty() and dll.back().first < nums[i]){
                dll.pop_back();
            }
            
            dll.push_back(make_pair(nums[i] , i));
            
            if(i>=k-1){
                ans.push_back(dll.front().first);
            }
         }
        
        return ans;
        
        
        
    }
};
