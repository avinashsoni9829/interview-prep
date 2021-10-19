count total number of bits 


int total(int n){
	int count = 0;
	
	while(n){
		count = count + 1;
		n>>=1;
	}
	return count;
	
}
