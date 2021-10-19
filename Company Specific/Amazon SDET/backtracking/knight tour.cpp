// knight tour problem 
/*
  worst time : O( 8 ^ (n^2))
  space : O( n * n )
  
*/
 
#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>&board){
	  int  n = board.size();
	  int  m = board[0].size();
	  
	  for(int  i = 0 ; i < n ; ++i){
	  	 for(int j = 0  ; j < m ; ++j){
	  	 	  cout<<board[i][j]<<" ";
		   }
		   
		   cout<<endl;
		   
	  }
	  
	  
}

void knighttour(vector<vector<int>>&board,int r ,int c,int moves){
	   // boundary check
	   
	   if( r >=board.size()  or c>=board[0].size() or  r < 0 or c < 0 or board[r][c] > 0){
	   	   return;
	   }
	   else
	   if(moves == board.size() * board.size()){
	   	  board[r][c] = moves;
	   	  display(board);
	   	  board[r][c] = 0 ;
	   	  return;
	   }
	   
	   
	   board[r][c] = moves;
	   
	   knighttour(board,r - 2 , c + 1 , moves + 1); 
	   knighttour(board,r - 2 , c + 2 , moves + 1);
	   knighttour(board,r + 1 , c + 2 , moves + 1);
	   knighttour(board,r + 2 , c + 1 , moves + 1);
	   knighttour(board,r + 2 , c - 1 , moves + 1);
	   knighttour(board,r + 1 , c - 1 , moves + 1);
	   knighttour(board,r - 1 , c + 2 , moves + 1);
	   knighttour(board,r - 2 , c - 1 , moves + 1);
	   
	   // backtrack
	   board[r][c] = 0;
	    
	    
}




int main(){
	   int r, c;
	   cin>>r>>c;
	   
	   vector<vector<int>>board(r,vector<int>(c,0));
	   
	   knighttour(board,r,c,1);
	   	
	   
}
