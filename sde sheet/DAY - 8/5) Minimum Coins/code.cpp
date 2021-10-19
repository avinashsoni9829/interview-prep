int v = value 

int deno  = { 1,2,5,10,20,50,100,500,1000};


int n =  9 ;

vector<int>ans;

for(int  i = n - 1; i>=0  ; i--)
{
	  while(v>=den[i])
	  {
	  	  v-=deno[i];
	  	  ans.push_back(deno[i]);
	  }
}

print ans 
