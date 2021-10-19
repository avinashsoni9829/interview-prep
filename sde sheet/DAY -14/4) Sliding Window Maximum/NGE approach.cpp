class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        
        int  n = nums.size();
        /*  Find the next greater element first */ 
        
        
        vector<int>NGE(n,-1);
        stack<int>st;
        
        st.push(n-1);
        NGE[n-1] = n;
        
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            while(st.size() > 0 and nums[i] >= nums[st.top()])
            {
               st.pop();
            }
            
            if(st.size() == 0)
            {
                  NGE[i] = n ;
            }
            else
            {
                  NGE[i] = st.top();
                
            }
            
            st.push(i);
            
        }
        
        int j = 0;
        for(int i = 0  ; i <= n - k  ; ++i)
        {
            if(j<i){
                j = i ;
            } 
            
            
            while(  NGE[j] < i + k )
            {
                 j = NGE[j];
            }
            
            ans.push_back(nums[j]);
            
            
        }
        
        return ans;
        
        
    }
};
