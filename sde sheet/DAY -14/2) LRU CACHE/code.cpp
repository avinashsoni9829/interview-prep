#include<bits/stdc++.h>
using namespace std;

class LRUcache{
	list<int>dll;
	
	unordered_map<int , list<int> :: iterator > cache ;
	
	int size;
	
	public:
	 
	LRUcache(int n)
	{
	  size = n;	
	}
	
	void refer(int x){
		
		if(cache.find(x) == cache.end()){
			 if(dll.size() == size){
			 	int removed = dll.back();
			 	
			 	dll.pop_back();
			 	
			 	cache.erase(removed);
			 	
			 }
		}
		else
		{
			 dll.erase(cache[x]);
		}
		
	
		dll.push_front(x);
	    cache[x] = dll.begin();		
	}
	
	void display(){
		
		for(auto it  = dll.begin() ; it!=dll.end();it++){
			
			cout<<*(it)<<" ";
		}
		cout<<endl;
	}
	
};


int main(){
	
	LRUcache q(4);
	
	q.refer(1);
	q.refer(2);
	q.refer(3);
	q.refer(1);
	q.refer(4);
	q.refer(5);
	q.display();
	
}



