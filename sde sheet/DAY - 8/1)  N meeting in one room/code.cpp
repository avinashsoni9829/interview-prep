/*
 time : O( n log n )
 space : O(N)

*/

#include<bits/stdc++.h>
using namespace std;

struct meeting{
	int s,e,pos;
	
};


bool comp(struct meeting & m1 ,struct meeting &m2)
{
	
	 
	      if(m1.e == m2.e){
	      	 return m1.pos < m2.pos ;
		  }
		  
		  return m1.e < m2.e;
}
	
void maxMeeting(int s[],int f[],int n){
	  
	  struct meeting meet[n];
	  
	  for(int  i = 0 ;  i < n ; ++i){
	  	  meet[i].s = s[i];
	  	  meet[i].e = f[i];
	  	  meet[i].pos =  i  + 1;
	  
	  
	  }
	  
	  sort(meet, meet + n , comp);
	  
	  vector<int>ans;
	  
	  ans.push_back(meet[0].pos);
      
      int limit = meet[0].e;
      
      
      for(int  i = 1 ; i < n ; ++i){
      	  if(meet[i].s >=limit){
      	  	  ans.push_back(meet[i].pos);
			  limit = meet[i].e;
			  
			}
			
	  }
	  
	  for(int  i = 0 ; i  < (int) ans.size(); ++i){
	  	 cout<<ans[i]<<" ";
	  	 
	  }
	  
	  cout<<endl;
	  
	  
}




int main(){
	  // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    maxMeeting(s, f, n);
    
}
