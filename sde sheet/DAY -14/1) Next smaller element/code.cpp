Next Smaller Element


void f(vector<int>a,int n)
{
	  stack<int>s;
	  
	  s.push(a[0]);
	  
	  for(int  i = 1 ; i < n ; ++i)
	  {
	  	  if(s.empty()) {
	  	  	s.push(a[i]);
	  	  	continue;
			}
			else
			{
				 while(!s.empty() and s.top() > a[i])
				 {
				 	  cout<<s.top() <<" -> " <<a[i];
				 	  s.pop();
				 }
				 
				 s.push(a[i]);
			}
	  }
	  
	  while(!s.empty())
	  {
	  	 cout<<s.top() <<"  -> "<< -1<<endl;
	  	 
	  	  s.pop();
	  }
}
