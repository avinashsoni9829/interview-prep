#include<bits/stdc++.h>
using namespace std;

/*
   ans flow 
   
   1)  sorting method
   
   2)  counting array method
   
   3) simulataneous eqn  method
   
   4) using value as index method
   
   5) xor method 
 
*/


/* --------------------------------------  SORTING METHOD ------------------------------------- */

void method1(vector<int>a,int n){
	 
	 int miss,rep;
	 
	 sort(a.begin(),a.end());
	 
	 
	 for(int i=0;i<n;++i){
	 	if(a[i]!=i+1){
	 		miss=i+1;
		 }
		 if(a[i]==a[i+1]){
		 	rep=a[i];
		 }
	 }
	 
	 
	 
	 cout<<"the missing number is "<<miss<<endl;
	 
	 
	 cout<<"the repetitng number is :"<<rep<<endl;
	 
	}
	

  /* --------------------------------------  COUNT  METHOD ------------------------------------- */	
	void method2(vector<int>a,int n){
		
		int count[n+1];
		memset(count,0,sizeof(count));
		
		for(int i=0;i<n;++i){
			count[a[i]]++;
		}
		
		
		int miss,rep;
		bool missfound=false,repfound=false;
		
		for(int i=1;i<=n;++i){
			
			
			if(repfound and missfound){
				break;
			}
			 
			 if(!count[i])
			 {  
			    miss=i;
			    missfound=true;
			    
		     } 
			 
			 if(count[i]>1){
			 	repfound=true;
			 	rep=i;
			 }
		 }
		 
     cout<<"the missing number is "<<miss<<endl;
	 
	 
	 cout<<"the repetitng number is :"<<rep<<endl; 
		 
		
	}

 /* --------------------------------------  ARRAY VALUE AS INDEX METHOD ------------------------------------- */	
	void method4(vector<int>a,int n){
		
		 //  i will use the value as an index and will make it negative so that i can see that it is traversed withing the array 
		 
		 int miss,rep;
		 
		 for(int i=0;i<n;++i){
		 	
		 	   if(a[abs(a[i])-1] > 0){
		 	   	  // this means that we have traversed this value 
		 	   	  a[abs(a[i])-1]= -a[abs(a[i])-1];
		 	   	 }
		 	   	 else
		 	   	 {
		 	   	     rep=abs(a[i]);	 
			     }
		   }
		   
		   for(int i=0;i<n;++i){
		   	  if(a[i]){
		   	  	  miss=i+1;
		   	  	  break;
				 }
		   	   
		   }
		   
	 cout<<"the missing number is "<<miss<<endl;
	 
	 
	 cout<<"the repetitng number is :"<<rep<<endl; 
		 
		   
		   
	}
	
	/* --------------------------------------  XORR METHOD ------------------------------------- */
	
	void method5(vector<int>a,int n){
		
		int xorr=0;
		
		for(int i=0;i<n;++i){
			xorr^=a[i];
		 }
		 
		 for(int i=1;i<=n;++i){
		 	xorr^=i;
		 }
		 
		 // now xorr has x^y in which one bit is repeating and another is missing 
		 
		 int x=0,y=0;
		 
		 int mask=(xorr) & (-xorr);  // RIGHT MOST SET BIT MASK
		
		
		 for(int i=0;i<n;++i){
		 	 if(a[i]&mask){
		 	 	 x^=a[i];
			  }
			  else
			  {
			  	 y^=a[i];
			  }
		 }
		 
		 for(int i=0;i<n;++i){
		 	
		 	 if(a[i]==x){
		 	 	
		 	 	 cout<<"Repeting is "<<x<<endl;
		 	 	 cout<<"Missing is "<<y<<endl;
		 	 	break;
		 	  }
		 	  else
		 	  if(a[i]==y){
		 	  	
		 	  	cout<<"Repeting is "<<y<<endl;
		 	 	 cout<<"Missing is "<<x<<endl;
		 	  	
			   }
	}
	
}

/*


  xor method explaination : 
  
  
   sabse pehle saare elements ka xor lelo 
   and uske baad 1 se N tak ke saare elements ka xor lelo
   
   isse jo result aayega usme x^y  hoga jisme se ek value reptiting h and dusri missing
   
   now ab x^y meh jis bit pe 1 h waha pe dono bit different h and jaaha 0 h waha dono bit same h 
   
   x^y =  all elemnts ka xor ^ 1 ^ 2^3 ... ^N
   
   now isme right most set bit me jaha pe 1 h waha se ek number apne ko milega 
   and jisme right most set bit me jaha pe 0 h whaa se ek dusra number milega
   
   isse apne ko x and y mil jaayenge 
   
   
   phir bas check karna h ki reptiting value konsa h 
   
   and then print the ans

*/


int main()
{
	 int n;
	 cin>>n;
	 
	 vector<int>a(n);
	 
	 for(auto &z:a) cin>>z;
	 
	// method1(a,n);
	 
	  // method2(a,n);
	  
	 // method3  = finding the sum and multiplication eqns and then finding the missing and the reptiting number 
	 
	 //method4(a,n);
	 
	 // xor approach 
	 method5(a,n);
	 
	 
	
}

