#include<bits/stdc++.h>
using namespace std;

string binrep(int n){
	string ans;
	
    for(int i = (1<<30) ; i > 0  ; i >>=1){
    	if(n&i){
    		ans+='1';
		}
		else
		{
			ans+='0';
		}
	}
	
	return ans;
	
}


int main(){
	
	cout<<binrep(9)<<endl;
	
	cout<<binrep(17)<<endl;
	
}
