#include<iostream>
using namespace std;


class node {
	 public : 
	    
	    int data;
	    node * next;
	    
	    node(int d){
	    	 data  = d;
	    	 next  = NULL;
		}
};


void insertAtHead(node * &head ,int val){
	node * curr = new node(val);
	curr->next = head;
	head = curr;
	
}


void insertAtTail(node*head,int val){
	node * last = new node(val);
	node * hold = head;
	
	while(hold->next!=NULL){
		hold = hold ->next;
		
	}
	
	hold ->next = last;	
}

void print(node *head){
	 if(head!=NULL){
	 	cout<<head->data;
	 	head = head -> next;
	 	
	 }
	 
	 while(head!=NULL){
	 	 cout<<"->"<<head->data;
	 	 head = head -> next;
	 }	
}


void inp(node * & head){
	int n;
	cin>>n;
	while(n!=-1){
		if(head == NULL){
			insertAtHead(head,n);
			
		}
		else
		{
			 insertAtTail(head,n);
		}
		cin>>n;
		
	}
}


ostream& operator <<(ostream & os,node *  head){
	print(head);
}
istream& operator >>(istream& is,node*&head){
	inp(head);
}

int main()
{
	node * head = NULL;
	cin>>head;
	cout<<head;
	
	return 0;
	
}

