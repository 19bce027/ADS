#include<bits/stdc++.h>
using namespace std;

class Node{
	public :
	Node* arr[4];
	int val;
	Node* next;

	Node(){
		arr[0] = arr[1] = arr[2] = arr[3] = NULL;
		next = NULL;
		val = 0;
	}
	Node(int data){
		val = data;
		arr[0] = arr[1] = arr[2] = arr[3] = NULL;
		next = NULL;
	}
};


Node* root = NULL;

void insert(Node* head , int val ){

	Node* newnode = new Node(val);

	if(head == NULL){
		root = newnode;
		newnode->arr[0] = newnode->arr[1] = newnode->arr[2] = newnode->arr[3] = root;
		return;
	}

	Node* temp = root;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newnode;
	temp->arr[0] = newnode;
}

int main(){
	vector<int>data = {1 ,3 ,5 , 6 , 7 , 8 , 9 , 15 , 20 , 21 , 23 , 25 , 26 , 29 , 30 , 32};
	int n = data.size();


	for(int i=0 ; i<n ; i++){
		insert(root , data[i]);
	}

    cout<< "\n----- connections after inserting all data -----" << endl ;

	Node* temp = root;
	cout<< "\nLevel 1 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;

	temp = root;
	Node* prev = NULL;
	while(temp!=NULL && temp->next!=NULL ){
		temp->arr[1] = temp->next->next;
		temp = temp->next->next;
		prev = temp;
	}
	if(prev!=NULL){
		prev->arr[1]->next = NULL;
	}


	temp = root;
	cout<< "\nLevel 2 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[1];
	}
	cout<<endl;

	temp = root;
	prev = NULL;
	while(temp!=NULL && temp->next!=NULL && temp->next->next!=NULL && temp->next->next->next!=NULL){
		temp->arr[2] = temp->next->next->next->next;
		temp = temp->next->next->next->next;
		prev = temp;
	}
	if(prev != NULL){
		prev->arr[2]->next = NULL;
	}


	temp = root;
	cout<< "\nLevel 3 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[2];
	}
	cout<<endl;

	temp = root;
	int t = 8;

	while(true){
		int tt = t;
		Node* prev = temp;
		while(tt-- && temp!=NULL){
			temp = temp->next;
		}

		prev->arr[3] = temp;
		if(temp == NULL){
			break;
		}
	}

	temp = root;
	cout<< "\nLevel 4 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[3];
	}
	cout<< "\n" <<endl;



	int x = 18;
 	int level = 3;

 	temp = root;

 	vector<Node*>v;
 	stack<Node*>st;
 	Node* newnode = NULL;

 	while(true){
 		Node*curr , *prev;
 		if(level == 0){
 			 curr = temp , prev = NULL;

 			while(curr!=NULL &&  curr->val < x){
 				prev = curr;
 				curr = curr->arr[0];
			 }
			  newnode = new Node(x);
			 prev->arr[0] = newnode;
			 newnode->arr[0] = curr;

 			break;
		 }

 		while(temp!=NULL && temp->val < x){
 			v.push_back(temp);
 			temp = temp->arr[level];
		 }


		temp = v.back();
		st.push(temp);
		level--;
	 }



	level = 1;
	while(!st.empty()){

		int x = rand()%2;
		cout<< "Result of toss : " << x <<endl;
		if(x == 1){

			Node* curr = st.top();
	 		Node* last = curr->arr[level];

	 		curr->arr[level] = newnode;
	 		newnode->arr[level] = last;
	 		st.pop();
	 		level++;
		}else{
			break;
		}
	}

    cout<< "\n----- connections after inserting 18 -----" << endl ;

	temp = root;
	cout<< "\nLevel 1 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[0];
	}
	cout<<endl;

	temp = root;
	cout<< "\nLevel 2 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[1];
	}
	cout<<endl;

	temp = root;
	cout<< "\nLevel 3 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[2];
	}
	cout<<endl;

	temp = root;
	cout<< "\nLevel 4 connections : " << endl ;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->arr[3];
	}
	cout<<endl;


}
