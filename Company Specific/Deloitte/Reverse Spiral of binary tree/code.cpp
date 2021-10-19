// reverse spiral view of a tree 
#include<bits/stdc++.h>
using namespace std;

struct node{
	struct node * left ,  * right ;
	int data;
    node(int data){
    	 this -> left = NULL;
    	 this -> right = NULL;
    	 this -> data  = data;
	}
	
	
 
};



int height(struct node * root){
	
	if(root == NULL){
		return 0 ;
	}
	
	int lheight = height(root -> left);
	int rheight = height(root -> right);
	
	return 1 + max(lheight , rheight);
	
}


void LeftToRight(struct node * root,int level){
	
	if(root == NULL) return ;
	if(level <= 0){
		return ;
	}
	if(level == 1){
		cout<<root -> data<<" ";
	}
	else
	if(level > 1){
		 LeftToRight(root -> left , level - 1);
		 LeftToRight(root -> right , level - 1);
		 
	}
	
}


void RightToLeft(struct node * root , int level){
	  if(root == NULL) return ;
	  
	  if(level <= 0 ){
	  	return ;
	  }
	  if(level == 1){
	  	 cout<<root -> data<<" ";
	  }
	  else
	  if(level > 1){
	  	RightToLeft(root -> right , level - 1);
	  	RightToLeft(root -> left , level - 1);
	  	 
	  }
}


void reverseclockwisespiral(struct node * root){
	  
	  int low = 1;
	  int high = height(root);
	  bool flag = 0 ;
	  while(low <= high){
	  	 if(flag == 0){
	  	 	 RightToLeft(root , high);
	  	     flag^=1;
			 high = high - 1;	
		  }
		  else
		  {
		  	 LeftToRight(root , low);
		  	 flag^=1;
		  	 low = low + 1;
		  }
	  }
}


int main(){	 
  struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right = new node(5);
 
    reverseclockwisespiral(root);
}


