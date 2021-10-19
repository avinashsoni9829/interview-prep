#include<bits/stdc++.h>
using namespace std;

/*

   method 1 
   
   time : O( n * n * n )
   space : O(1)

*/

bool isPalindrom(string s){
	string temp = s;
	reverse(s.begin(),s.end());
	return temp == s;
}


string method1(string s,int n){
	string ans;
	int mxLen = -1 ;
	
	for(int i = 0 ; i < n - 1; ++i){
		 string curr;
		 for(int j = i + 1; j <  n; ++j){
		 	cur = curr + s[j];
		 	r
		 	if(isPalindrom(curr)){
		 		int len = curr.length();
		 		
		 		if(len > mxLen){
		 			mxLen = len ;
		 			ans = curr;
				 }
			 }
		 	
		 }
	}
	
	return ans;
	
}


/*

 DP solution [ will do later  ] 
 time : O( n * n )
 space : O( n * n )

*/


/*
   METHOD  2
    using even and odd centers 
   
    time : O ( n * n )
    space : O(1)
    
*/


int method2(string s){
	
	int mxlen = 1;
	int start = 0;
	int len = s.length();
	
	int low , high ;
	
	for(int i = 1 ; i < len ; ++i){
		
		 // even center 
		low = i - 1;
		high = i ;
		
		while(low >=0 and  high <= len - 1 and s[low] == s[high]){
			
			low = low - 1;
			high = high + 1;
			
		} 
		
		// move back 
		low = low + 1;
		high = high - 1;
		
		
		if(s[low] == s[high] and high - low +  1 > mxlen){
			start = low ;
			mxlen = high - low + 1;
		}
		
		// odd center  
		
		
		low = i - 1;
		high= i + 1;
		
		while(low >=0  and high <=len - 1  and s[low] == s[high]){
			 low  = low - 1;
			 high = high + 1;
		}
		
		low = low + 1;
		high = high - 1;
		
		
		if(s[low] == s[high] and high - low  + 1 > mxlen){
			 start = low ;
			 mxlen = high - low + 1;
		}
		
		
	}
	
	int ans = mxlen;
	
	while(ans){
		 cout<<s[start]<<" ";
		 start = start + 1;
		 ans = ans - 1;
	}
	
	return mxlen;
	
}




int main()
{
	string s;
	cin>>s;
	
	//cout<<method1(s,s.length())<<endl;
	cout<<method2(s)<<endl;
	 
}
