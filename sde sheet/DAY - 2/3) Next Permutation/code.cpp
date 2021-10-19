#include<bits/stdc++.h>
using namespace std;

/*     Next Permutation        */

// first approach would be to print all recursively and then find 


// optimal approach    time : O(n)   space : O(1) 

    void next_perm(vector<int>a)
    {
    	    int n=a.size();
    	    
    	    int i,j;
    	    // step 1  :  find the element a[i] < a[i+1]   ( first decreasing part element)
    	    for(i=n-2;i>=0;i--)
    	    {
    	    	  if(a[i]<a[i+1])
    	    	  {
    	    	  	  break;
				  }
    	    }
    	    
    	    if(i<0)
    	    {
    	    	  reverse(a.begin(),a.end());
			}
			else
			{
				   // step 2 :  find the element greater than a[i] in from right to left in increasing part 
				    
				    for(j=n-1;j>=0;j--)
				    {
				    	  if(a[j]>a[i])
				    	  {
				    	  	  break;
						  }
					}
					
					// step 3  :  swap a[i] and a[j]  
					
					swap(a[i],a[j]);
					
					// step 4 :  make the i + 1  - n  half again increasing to find the lower lexicographical value
					
					reverse(a.begin() + i + 1 , a.end());
					
			}
			
			
			for(auto z:a)
			{
				  cout<<z<<" ";
			}
			cout<<endl;
			
	}
  

int main()
{
	
	 int n;
	 cin>>n;
	 
	 vector<int>a(n);
	 
	 for(auto &z:a) cin>>z;
	 
	 
	 next_perm(a);

}


