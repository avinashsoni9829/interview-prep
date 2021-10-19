#include<bits/stdc++.h>
using namespace std;

/*
   time : O(n + m)
   space : O(n)
   
*/
void makeLPS(string pat,int m,vector<int>&lps){
	 int prefix_len = 0;
	 lps[0] = 0;
	 
	 int idx = 1;
	 while(idx < m){
	 	 if(pat[idx] == pat[prefix_len]){
	 	 	prefix_len = prefix_len + 1;
	 	 	lps[idx] = prefix_len;
	 	 	idx = idx + 1;
		  }
		  else
		  {
		  	  if(prefix_len!=0){
		  	  	prefix_len = lps[prefix_len -1];
		  	  	}
		  	  	else
		  	  	{
		  	  	 lps[idx] = 0;
					 idx = idx +1;	  
				}
		  }
	 }
}


void kmp(string pat,string txt){
	 int m = pat.length();
	 int n = txt.length();
	 
	 vector<int>lps(m);
	 
	 makeLPS(pat,m,lps);
	 
	 int i = 0 , j = 0 ;
	 
	 while(i<n){
	 	if(pat[j] == txt[i]){
	 		 i = i + 1;
	 		 j = j + 1;
		 }
		 if(j==m){
		 	cout<<"Pattern at  idx = "<<i-j<<endl;
		 	 j = lps[j-1];
		 	 
		 }
		 else
		 if(i< n and pat[j]!=txt[i]){
		 	if(j!=0){
		 		j  = lps[j-1];
		 		
			 }
			 else
			 {
			 	i = i + 1;
			 }
		 }
	 }
}


int main(){
	 	string txt = "ABABDABACDABABCABAB";
	 	string pat = "ABABCABAB";
	 	
	 	kmp(pat,txt);
	 	
}
