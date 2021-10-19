#include<bits/stdc++.h>
using namespace std;

int main(){
	  
	  vector<int>inorder , preorder , postorder;
	  stack<pair<Node *,int>>st;
	  
	  st.push(make_pair(root,1));
	  
	  while(!st.empty()){
	  	  pair<Node *, int > tp = st.top();
	  	  Node  * node = tp.first ;
	  	  int flag = tp.second;
	  	  if(flag==3){
	  	  	postorder.push_back(node->data);
	  	  	st.pop();
			}
			else
			if(flag == 2){
				inorder.push_back(node->data);
				s.push(make_pair(node -> right ,3));
				 
			}
			else
			if(flag == 1){
				 preorder.push_back(node -> data);
				 s.push(make_pair(node -> left , 2));
			}
	  }
	  
	  for(auto z: inorder) cout<<z<<" ";
	  for(auto z: preorder) cout<<z<<" ";
	  for(auto z: postorder) cout<<z<<" ";
	  
	  
}
