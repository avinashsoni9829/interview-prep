#include<bits/stdc++.h>
using namespace std;

/* Reverse Pairs 
 
   Method 1 )  brute force    time  : O(n * n)  space  : O(1)
   
 */


int method1(vector<int>a,int n)
{
    int ans=0;
	
	for(int i=0;i<n;++i)
	{
	   for(int j=0;j<n;++j)
	   {
	      if(i<j and a[i]>2*a[j])
		  {
		     ans++;	  
		  }	  
	   }	 
    }  	   
    
    return ans;
    
 
} 

/*

   method 2 :  using merge sort
   
   time  :  o(nlogn) + 2 * O(n)
   space : O(n)
   

*/
int res=0;

    void merge(vector<int>& nums,int left,int mid,int right){
    	
        int n = mid-left+1;
        int m = right-mid;
        
		vector<int> vec1(n);
        vector<int> vec2(m);
        
		    for(int i=0;i<n;i++)
            vec1[i] = nums[left+i];
        
		    for(int i=0;i<m;i++)
            vec2[i] = nums[mid+1+i];
        
		int i=0;
        
		int j=0;
        
		int k=left;
        
		while(i < n && j < m){
            if(vec1[i] > (long)2*vec2[j]){
                res+=(n-i);
                j++;
            }else{
                i++;
            }
        }
        
		i=0;
        j=0;
        
		while(i < n && j < m){
            if(vec1[i] < vec2[j]){
                nums[k++] = vec1[i++];
            }else{
                nums[k++] = vec2[j++];
            }
        }
        
		while(i < n)
            nums[k++] = vec1[i++];
        
		while(j < m)
            nums[k++] = vec2[j++];
    }
    void mergeSort(int s,int e,vector<int>& nums){
        
		if(s < e){
            int mid = (e+s)/2;
            mergeSort(s,mid,nums);
            mergeSort(mid+1,e,nums);
            merge(nums,s,mid,e);
        }
    }
    int method2(vector<int>& nums) {
        
		mergeSort(0,nums.size()-1,nums);
        
		return res;
    }
 
 
/*
   other methods :
    using Segment Tree
    Fenwick Tree
    Binary Search Tree
    AVL tree
    




*/


int main()
{
	
	 int n;
	 cin>>n;
	 
	 vector<int>a(n);
	 
	 for(auto &z:a) cin>>z;
	 
	 //cout<<method1(a,n)<<endl;
    cout<<method2(a)<<endl;

	
	 
    
}


