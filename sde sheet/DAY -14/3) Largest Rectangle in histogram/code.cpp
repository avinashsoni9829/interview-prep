class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>st;
        
        heights.push_back(0);
        
        
        int ans = 0 ;
        
        
        for(int  i = 0 ; i < heights.size() ; ++i){
            
            while(st.size() > 0  and heights[st.top()] >= heights[i]){
                int vertical = heights[st.top()];
                st.pop();
                
                int more  = st.size() > 0  ? st.top() : -1;
                
                int horizontal = ( i - more - 1);
                
                ans = max(ans, vertical * horizontal);
                
            }
            
            st.push(i);
        }
        
        return ans;
        
        
    }
};
