// rat in a maze problem 

#include<bits/stdc++.h>
using  namespace std;



bool check(vector<vector<int>>&board , int  r, int c){
	  int n = board.size();
	  int m = board[0].size();
	  
	  if( r >= 0  and r < n and c >=0 and c<m and board[r][c] == 1) return true;
	  return false;
}

bool helper(vector<vector<int>>&board , int x , int y , vector<vector<int>>&sol){
	  if(x == board.size() - 1 and y == board[0].size() - 1 and board[x][y] == 1){
	  	   sol[x][y] = 1;
	  	   return true;
	  }
	  
	  if(check(board,x,y) == true){
	  	 if(sol[x][y] == 1){
	  	 	return false;
		   }
		sol[x][y] = 1;
		
		if(helper(board , x + 1 , y , sol)== true) return true;
		if(helper(board , x , y + 1, sol) == true) return true;
		
		// back track
		sol[x][y] = 0 ;
		return false;
		
	  }
	  
	  return false;
	  
}







bool solve(vector<vector<int>>&board,int r,int c){
	  vector<vector<int>>copy = board;
	  for(int i = 0 ; i  < r ; ++i){
	  	for(int  j = 0  ; j  < c ; ++j){
	  		  copy[i][j] = 0 ;
		  }
	  }
	  
	  if(helper(board , 0 , 0 ,copy) == false){
	  	 cout<<"No solution"<<endl;
	    return false;
	  }
	  else
	  {
	  	 display(board);
	  	 return true;
	  }
}

int main(){
	  int r , c;
	  cin>>r>>c;
	  vector<vector<int>>board(r,vector<int>(c,0));
	  
	  for(int  i =  0 ; i < r ; ++i){
	  	for(int  j = 0 ;  j < c ; ++j){
	  		  cin>>board[i][j];
		  }
	  }
	  
	  
	  solve(board,r,c);
}
