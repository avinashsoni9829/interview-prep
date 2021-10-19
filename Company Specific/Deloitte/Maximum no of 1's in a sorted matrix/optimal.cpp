/*

   time : O ( n  + m ) 
   space : O (1)
   
   
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	  
	  int n , m ;
	  cin>>n>>m;
	  
	  int a[n][m];
	  
	  for(int  i = 0 ; i < n ; ++i){
	  	 for(int  j = 0 ; j < m ; ++j){
	  	 	  cin>>a[i][j];
		   }
	  }
	  
	  
	   int ans_row = 0;
	   
	   int y = m - 1;
	   
	   
	   for(int  i = 0 ;  i < n ; ++i){
	   	    bool more =  false;
	   	    
	   	    while(y >=0 and a[i][y] == 1){
	   	    	y = y - 1;
	   	    	more = true;
			   }
			   if(more){
			   	ans_row = i;
			   }
			   
		}
		
		if(ans_row == 0  and a[0][m-1] == 0) cout<<-1<<endl;
		
		
	  
	  cout<<"Max no of 1s are : "<<ans_row<<endl;
	  
	  
	  
	  
	  
}
