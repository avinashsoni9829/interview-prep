#include<bits/stdc++.h>
using namespace std;
 
 
 /*
 
    flow of ans :
    
     1) bubble sort   O(n^2) 
     2) bubble sort with flag optimization  O(n^2)
     3) merge sort  O(nlogn)  +  extra space
     4) count variable method  O(n) +  O(1)
     5) dutch flag algo     O(n) + O(1)
 
 
 */
 
 
 
 
 /*    ---------------------------  BUBBLE SORT  ---------------------------- */
 
 
  
 void method1(vector<int>&a,int n){
 	
 	     for(int i=0;i<n-1;++i){
 	     // i elements will be at correct place 
 	       for(int j=0;j<n-i-1;++j){
 	       	  
 	       	    // previous element is greater , so we will swap them
 	       	     if(a[j]>a[j+1]){
 	       	     	
 	       	     	swap(a[j],a[j+1]);
					
					}
 	       	
			}
		  }
 }
  
 /*    ---------------------------  BUBBLE SORT with FLAG optimization  ---------------------------- */

  
 void method2(vector<int>&a,int n){
 	
 	 for(int i=0;i<n-1;++i){
 	     
		     bool swapped=false;
		     // i elements will be at correct place 
 	       for(int j=0;j<n-i-1;++j){
 	       	   
 	       	    // previous element is greater , so we will swap them
 	       	     if(a[j]>a[j+1]){
 	       	     	
 	       	     
 	       	     	     swap(a[j],a[j+1]);
 	       	     		 swapped=true;
					
					}
 	       	
			}
			
			if(!swapped){
				break;
				
			}
		  }
 
 
 }
 
 /*    ---------------------------  MERGE SORT  ---------------------------- */
 
 void helper(vector<int>&a,int low,int mid,int high){
 	
 	    int i,j,k;
 	    
 	    int left[mid-low+1];
 	    int right[high-mid];
 	    
 	    for(int i=0;i<(mid-low+1);++i){
 	    	left[i]=a[i+low];
		 }
		 
		 for(int j=0;j<(high-mid);++j){
		 	right[j]=a[mid+1+j];
		 }
		 
		 
		 i=0;
		 j=0;
		 k=low;
		 
		 while(i<(mid-low+1) and j<(high-mid)){
		 	
		 	   if(left[i]<right[j]){
		 	   	  
		 	   	    a[k++]=left[i];
		 	   	    i++;
		 	   	}
		 	   	else
		 	   	{
		 	   		  
			         a[k++]=right[j];
			         j++;
			    }
		 	
		 }
		 
		 while(i<(mid-low+1)){
		 	
		 	   a[k++]=left[i];
		 	   i++;
		 }
		 
		 while(j<(high-mid)){
		 	
		 	a[k++]=right[j];
		 	j++;
		 }
 }
 
 void method3mergesort(vector<int>&a,int low,int high){
 	  
	  if(low<high)
	  {
	  	
		int mid=(low+high)/2;
	  	
		method3mergesort(a,low,mid);
	  	method3mergesort(a,mid+1,high);
	  	helper(a,low,mid,high);
	  
	  }
}
 
 /*    ---------------------------  Variable Count Method  ---------------------------- */
 
 void method4(vector<int>&a,int n){
 	 
 	  // use pre defined function or i can use just populate three variables with  a for loop
 	  
 	  int count0=0,count1=0,count2=0;
 	  
 	  // first count0 numbers as 0 then so on for others   O(n) and O(1) space
 	  
 	  for(int i=0;i<n;++i)
	   {
 	  	count0+=(a[i]==0);
 	  	count1+=(a[i]==1);
 	  	count2+=(a[i]==2);
	   }
	   
	   int curr=0;
	   
	   while(count0--)
	   {
	   	a[curr]=0;
	   	curr++;
	   }
	   while(count1--)
	   {
	   	a[curr]=1;
	   	curr++;
	   }
	   
	   while(count2--)
	   {
	   	a[curr]=2;
	   	curr++;
	   }
	
 }
 
 /*    ---------------------------  DUTCH FLAG ALGO  ---------------------------- */
 
 void dutchflagalgo(vector<int>&a,int n){
 	
 	   /* 
 	        
			 
			   Algo : 
 	      
 	        take three pointers low , curr , high
 	        
 	        low=0
 	        curr=0;
 	        high=n-1;
 	        
 	         incrementing the curr and we will see what element we are getting 
 	         
 	         if element is  0 then we know that 0 will come in the first half so we will just swap it with low pointer 
 	         
 	         if element is 1 then we will continue incrementing curr
 	         
 	         if element is 2 then we swaap with high pointer and will not proceed the curr as element swapped from back might not be checked 
 	         
 	        */
			 
			 
			 int low=0,curr=0,high=n-1;
			 
			 while(curr<=high){
			 	
			 	if(a[curr]==0){
			 		swap(a[low],a[curr]);
			 		low+=1;
			 		curr+=1;
				 }
				 else
				 if(a[curr]==1){
				 	
				 	curr+=1;
				 }
				 else
				 {
				 	   swap(a[curr],a[high]);
				 	   high-=1;
				 }
			 } 
 }




int main(){
	
	   int n;
	   cin>>n;
	   
	   vector<int>colors(n);
	   
	   for(auto &z:colors) cin>>z;
	  
	   //  0 1 2  sort algorithm 
	   
	   //method1(colors,n);
	    //method2(colors,n);
	    
	    //method3(colors,n);
	   // method3mergesort(colors,0,n-1);
	   
	    //method4(colors,n);
	    
	    dutchflagalgo(colors,n);
	   
	   for(auto z:colors) cout<<z<<" ";
	   
	   cout<<endl;
	   
	   
}
