//largest area in a histogram

int largestarea(vector<int>heights){
	  stack<int>st;
	  
	  height.push_back(0);
	  
	  int ans = 0 ;
	  
	  for(int i = 0  ; i < heights.size() ; ++i){
	  	   while(st.size() and heights[st.top] >= heights[i]){
	  	   	   int v = heights[st.top()];
	  	   	   st.pop();
	  	   	   
	  	   	   int more = st.size > 0 ? st.top() : -1;
	  	   	   
	  	   	   int h = ( i  - more - 1);
	  	   	   
	  	   	   ans = max(ans ,h * v);
	  	   	   
			 }
			 
			 st.push(i);
			 
	  }
	  
	  cout<<ans<<endl;
	  
}

