#include<bits/stdc++.h>
using namespace std;



/*   ---------------------------------   Method 1  ----------------------------------------- */

/* 
    Brute force method 
    
     time  : O( m * n )
     space : O( m * n )

*/

void method1(vector<vector<int>>&grid,int n,int m)
{
	 
	  vector<vector<int>>temp;
	  temp=grid;
	  
	  for(int i=n-1;i>=0;--i)
	  {
	  	   for(int j=m-1;j>=0;--j)
	  	   {
	  	   	  
		       if(grid[i][j]==0)
		       {
		       	    for(int k=0;k<n;++k)
		       	    {
		       	        temp[k][j] = 0;	  
					}
					
					for(int u=0;u<m;++u)
					{
						  temp[i][u] = 0;
					}
			   }
		   
		   }
	  }
	  
	  grid = temp;	
}


/*   ---------------------------------   Method 2  ----------------------------------------- */

/* 
    
    
     time  : O( m * n )
     space : O( n + m )


*/

void method2(vector<vector<int>>&grid,int n,int m )
{
	   vector<int>row(n,-1);
	   vector<int>col(m,-1);
	   
	   for(int i=n-1;i>=0;--i)
	   {
	      
	       for(int j=m-1;j>=0; --j)
	       {
	       	   if( grid[i][j]==0)
	       	   {
	       	   	     row[i]=0;
	       	   	     col[j]=0;
			      
			   }
		   }
	      	   	 
	   }
	   
	   
	   for(int i=n-1;i>=0;--i)
	   {
	   	   for(int j=m-1;j>=0;--j)
	   	   {
	   	   	   
		       if(row[i]==0 or col[j]==0)
		       {
		       	    grid[i][j] = 0;
			   }
		   
		   }
	   }
}


/*   ---------------------------------   Method 3  ----------------------------------------- */

/* 
     optimal approach
    
     time  : O( m * n )
     space : O( 1 )


*/


void method3(vector<vector<int>>&grid,int n,int m)
{
	   bool firstzero=false;
	   
	   for(int i=0;i<n;++i)
	   {
	   	   for(int j=0;j<m;++j)
	   	   {
	   	   	   if(grid[i][j]==0)
	   	   	   {
	   	   	         if(i==0)
				    {
				    	
				         firstzero=true;
					}
					else
					{
					  	
	     			  grid[i][0]=0;
					}
					
					grid[0][j]=0;		   	  
			   }
		       
		   }
	   }
	   
	   
	   for(int i=n-1;i>=0;i--)
	   {
	   	  for(int j=m-1; j>=0 ; j--)
	   	  {
	   	  	  
	   	  	   if(i!=0)
	   	  	   {
	   	  	   	
				if(grid[i][0] == 0 or (grid[0][j]==0) )
				{
					   grid[i][j] =0;
				}
		     
		      }
		  }
	   }
	   
	   if(firstzero)
	   {
	   	   for(int i=0;i<m;++i)
	   	   {
	   	       grid[0][i]=0;	  
		   }
	   }
	   
	   
}








int main()
{
	
	 int n,m;
	 cin>>n>>m;
	 
	 
	 
	 
	 vector<vector<int>>grid(n,vector<int>(m));
	 
	 for(int i=0;i<n;++i)
	 {
	 	   for(int j=0;j<m;++j)
	 	   {
	 	   	   cin>>grid[i][j]; 
		      
		   }
	 }
	 
	 
	 //method1(grid,n,m);
	 //method2(grid,n,m);
	 method3(grid,n,m);
	 
	 for(auto z:grid)
	 {
	 	  for(auto k : z)
	 	  {
	 	  	  
	 	  	   cout<<k<<" ";
		  
		  }
		  
		  cout<<endl;
		  
	 }


}


