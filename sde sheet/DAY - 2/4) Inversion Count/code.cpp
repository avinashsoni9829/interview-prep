#include<bits/stdc++.h>
using namespace std;   
#define debug(a) cout << #a << "=" << a << ' '<<endl;
/**************************************** INVERSION COUNT ********************************************************/

 /*
   
   Methods :                                                     time complexity                         space complexity 
                                                          
    1)  Brute Force Approach                                        O( n * n )                                 O(1)
    2)  Merge Sort Method                                           O( n * log n )                             O(n)
    3)  Binary Indexed Tree Method  (Fenwick Tree)                  O( n * log(maxelement) )                   O(maxelement)
    4)  Set STL method
   Other Methods  : 
   
    1) AVL tree (Balanced Binary Tree)  Method 
    2) PBDS Method 
    3) Using Trie 
 
 
 */
 
 
 
  /*
  
                     METHOD 1  :  simple brute force approach  
                    
                     Time  :   O( n * n )
                     
					 Space :   O(1)
  
  */
  
  
  int method1(vector<int>a,int n)
  {
  	   int ans=0;
  	   
  	   for(int i=0;i<n;++i)
  	   {
  	   	   for(int j=0;j<n;++j)
  	   	   {
  	   	   	     if( i<j and a[i] > a[j] )
  	   	   	     {
  	   	   	        ans++;	  
				 }
		      
		   }
  	   	   
	      
	   }
	   
	   return ans;
	   
  }
  
  
   /*
  
                     METHOD 2  :  merge sort  approach  
                    
                     Time  :   O ( n * log n )
                     
					 Space :   O (n)
  
  */
  
  int _merge(vector<int>&a,vector<int>&temp,int low,int mid,int high)
  {
  	     int ans=0;
  	     int i,j,k;
  	     
  	     i=low;
  	     j=mid;
  	     k=low;
  	     
  	     while( (i<=mid-1)  and (j<=high))
  	     {
  	         
			    if( a[i] <= a[j] )
				{
				    temp[k++] = a[i++];	  
				}
				else
				{
				    temp[k++] = a[j++];
					// here a[i] > a[j] 
					ans+=(mid-i);	 
				}	  
	     }
		 
		 
		 while(i<=mid-1)
		 {
		    temp[k++] = a[i++];	 
 		 }   
         
		 while(j<=high)
		 {
		     temp[k++] = a[j++]; 
		 }
		 
		 
		 for(int i=low;i<=high ; i++)
		 {
		   	 a[i] = temp[i];
		 
		 }
		 
		 return ans;
  
  
  }      
  
  
  
  int __helper(vector<int>&a,vector<int>&temp,int low,int high)
  {
  	     int ans=0;
  	     
  	     if(low<high)
  	     {
  	     	   
		   int mid= (low + high )/ 2;
		   
		   ans+=__helper(a,temp,low,mid);
		   ans+=__helper(a,temp,mid+1,high);
		   ans+=_merge(a,temp,low,mid+1,high);
		 }
		 
		 return ans;
  }
  
  
  
  
  
  int  method2(vector<int>a,int size)
  {
  	   vector<int>temp(size);
  	   
  	  return __helper(a,temp,0,size-1);
  }
  
  
  /*     Binary Indexed Tree Method 
           
       time :   O( n * log(maxelement) )
	  
	   space  :  O( maxElement) 
	   
	   
	   let us say our inversion finding array is 	 8  4 2 1 
	   
	   then  
	   
	   bit[9] =   0 1 2 3 4 5 6 7 8 9
	     val  =   0 0 0 0 0 0 0 0 0 0 
	     
	     i=3 invcount=0
	         bit[9] =   0 1 2 3 4 5 6 7 8 9
	           val  =   0 1 0 0 0 0 0 0 0 0
	     
		 i=2     invcount = 1
		      bit[9] =   0 1 2 3 4 5 6 7 8 9
	            val  =   0 1 2 0 0 0 0 0 0 0      
	                        
	                        
	                        
	      i=1
	           bit[9] =   0 1 2 3 4 5 6 7 8 9
	             val  =   0 1 1 0 3 0 0 0 0 0 
		  i=0
		        bit[9] =   0 1 2 3 4 5 6 7 8 9
	             val  =   0  1 2 0 3 0 0 0 6 0
				 
				 ans = 6
				 
				  
		                      
							 
      i: 0 1 2 3  
         8 4 2 1
         
         
      in case the values are more then use coordinate compression to solve the problem !
	     
  */ 
  
  
  
  int sum(int bit[],int idx)
  {
  	  int ans=0;
  	    while(idx>0)
  	    {
  	    	ans+=bit[idx]; 
  	    	 
			idx = idx - (idx & (- idx));    
		
		}
		
		return ans;
  }
  
  
  void upd(int bit[],int n,int idx,int val)
  {
  	   while(idx<=n)
       {
       	    bit[idx]+=val;
       	    
       	    idx = idx + (idx & (-idx));
	   }
  }
  
  
  int method3(vector<int>a,int n)
  {
  	    int mx=*max_element(a.begin(),a.end());
  	    
  	    
  	    int ans=0;
  	    
  	    int bit[mx + 1];
  	    memset(bit,0,sizeof(bit));
  	    
	
		for(int i=n-1;i>=0;--i)
  	    {
  	       
			  ans+= sum(bit,a[i]-1);
			  
			  
			  upd(bit,mx,a[i],1);
	    }
	    
	    return ans;
  }
  
  
 
 /*
 
    Method 4 :
    
    Using Set 
 
     time  :   O(n * n)   
    
  */ 
  
  
  int method4(vector<int>a,int n)
  {
  	   multiset<int>s;
  	   
  	   s.insert(a[0]);
  	   
	   int ans=0;
  	   
	   multiset<int>::iterator it;
	   
	   for(int i=1;i<n; i++)
	   {
	   	   s.insert(a[i]);
	       
	       it=s.upper_bound(a[i]);
	       
	       ans+=distance(it,s.end());
	   }
	   
	   return ans;
	   
	   
  }
  
  

  



int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	
 	
 	int n;
 	cin>>n;
 	
 	vector<int>a(n);
 	
 	for(auto &z:a) cin>>z;
 	
 	//cout<<method1(a,n)<<endl;
 	//cout<<method2(a,n)<<endl;
 	//cout<<method3(a,n)<<endl;
 	 cout<<method4(a,n)<<endl;
 	 
 	

}


