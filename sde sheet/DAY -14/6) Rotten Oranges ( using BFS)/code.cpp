#include<bits/stdc++.h>
using namespace std;

int main(){
	
	  int  t;
	  cin>>t;
	  
	  while(t--){
	  	  int r,c;
	  	  cin>>r>>c;
	  	  
	  	  int a[r][c];
	  	  
	  	  for(int i = 0; i< r ; ++i){
	  	   for(int j = 0 ; j < c ; ++j){
	  	   	cin>>a[i][j];
			 } 	
		 }
		 
		 // making the queue
		 queue<pair<pair<int,int> , int >>q;
		 // setting the directions 
		 int dx[4] = {0,0,-1,1};
		 int dy[4] = {-1,1,0,0};
		 
		 // visited array
		 int vis[r][c];
		 
		 memset(vis,false,sizeof(vis));
		 
		 
		 for(int i = 0 ; i < r ; ++i){
		 	for(int j = 0 ; j < c ; ++j){
		 		 
				  // storing all rotten oranges 
				  
				  if(a[i][j] == 2){
		 		 	 q.push({{i,j},0});
		 		 	 vis[i][j] = true;
				  }
			 }
		 }
		 
		 
		 
		 int ans = -1;
		 
		 while(!q.empty()){
		 	  auto f = q.front();
		 	  // x cordinate , y coordinate , currtime 
		 	  int x = f.first.first;
		 	  int y = f.first.second;
		 	  int time = f.second;
		 	  
		 	  for(int i = 0 ; i < 4 ; ++i)
			   {
		 	  	
		 	  	  int xx = x + dx[i];
		 	  	  int yy = y + dy[i];
		 	  	  
		 	  	  if((xx>=0 and xx<r) and (yy>=0 and yy<c) and vis[xx][yy] == false){
		 	  	  	 
		 	  	  	     if(a[xx][yy] == 1){
		 	  	  	        a[xx][yy] = 2;
							vis[xx][yy] = true;
							// pushing the newly rotten orange 
							
							q.push({{xx,yy},time + 1});
							
							ans = time + 1;	  
						
						 }
						 else
						 {
						 	 vis[xx][yy] = true;
						 	 
						 }
		 	  	  	 
		 	  	  	 
					 }
			   }
			   
			   q.pop();
			   
			   
		 }
		 
		 // final check 
		 
		 bool f = 	true;
		 
		 for(int i = 0 ;  i < r ; ++i){
		 	 for(int j = 0 ; j < c ; ++j){
		 	 	  if(a[i][j] == 1){
		 	 	  	  f = false;
		 	 	  	  break;
					}
			  }
			  if(f == false){
			  	 break;
			  }
		 }
		 
		 if(f == false){
		 	 cout<<-1<<endl;
		 }
		 else
		 {
		 	 cout<<ans<<endl;
		 }
		 
		 	
	  }
}
