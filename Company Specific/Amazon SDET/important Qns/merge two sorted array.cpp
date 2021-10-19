//merge two sorted array without extra space 


void merge(vector<int>a, vector<int>b){
	 int n = a.size();
	 int m = b.size();
	 
	 if(n == 0) print(a);
	 if(m == 0) print(b);
	 
	 int  i = 0 , j = 0 , k = n - 1;
	 
	 while( i < k and  j < m){
	 	  if(a[i] < b[j]){
	 	  	   i = i  + 1;
		   }
		   else
		   {
		   	  swap(b[j] , a[k]);
		   	  j = j + 1;
		   	  k = k - 1;
		   }
	 }
	 
	 sort(a);
	 sort(b);
	 
}
