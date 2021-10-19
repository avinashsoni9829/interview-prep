Check if a number is power of 2 


method 1 : 

bool ispow2(int n)
{
	  if( n== 1){
	  	return true;
	  }
	  else
	  if(n%2!=0 or n==0) return false;
	  
	  return ispow2(n/2);
	  
}


method 2 : 

bool ispow2(int n)
{
	  if(n==0) return false;
	  
	  while(n!=1)
	  {
	  	  if(n%2!=0){
	  	  	return false;
			}
			n = n / 2;
	  }
	  
	  return true;
}



method 3: 

bool ispow2(int n)
{
	  if(n==0) return false;
	  
	  return ceil(log2(n))==floor(log2(n));
}


method 4 : 


bool ispow2(int n)
{
	  return n & !( n & (n-1));

    // rsb =  n & (n -1 )  
    // n for checking if n > 0
} 
