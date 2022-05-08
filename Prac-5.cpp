#include<bits/stdc++.h>
using namespace std;
#define COUNT 10

struct Node{
	int val;
	Node* left;
	Node* right;

	Node(int n){
		val = n;
		left = right = NULL;
	}
};

vector<Node*>l , r;

void splittree(Node* root , int tar){

	if(root == NULL){
		return;
	}

	if(root->val == tar){
		if(root->left != NULL){
			l.push_back(root->left);
		}
		if(root->right != NULL){
			r.push_back(root->right);
		}
		root->left = NULL ;
		root->right = NULL;
	}else if(tar < root->val){
		r.push_back(root);
		splittree(root->left , tar);
		root->left = NULL;
	}else if(tar > root->val){
		l.push_back(root);
		splittree(root->right , tar);
		root->right = NULL;
	}
}


Node* leftMerge(vector<Node*>l){
	int sz = l.size();

	while(l.size() >= 2){
		Node* t1 = l.back();
		l.pop_back();
		Node* t2 = l.back();
		l.pop_back();

		if(t1->val < t2->val){
			t1->right = t2;
			l.push_back(t1);
		}else{
			t2->right = t1;
			l.push_back(t2);
		}
	}

	return l.back();

}


Node* rightMerge(vector<Node*>r){
	int sz = r.size();

	while(r.size() >= 2){
		Node* t1 = r.back();
		r.pop_back();
		Node* t2 = r.back();
		r.pop_back();

		if(t1->val > t2->val){
			t1->left = t2;
			r.push_back(t1);
		}else{
			t2->left = t1;
			r.push_back(t2);
		}
	}

	return r.back();
}


void printTree(Node *root,int space){  //for printing bst in tree format

    if(root){
        space+=COUNT;
        printTree(root->right,space);
        for(int i=COUNT;i<space;i++) cout<<" ";
        cout<<root->val<<"\n";
        printTree(root->left,space);
    }
}
int main(){

	Node* root = NULL;
	Node* node40 = new Node(42);
	Node* node20 = new Node(19);
	Node* node50 = new Node(49);
	Node* node10 = new Node(15);
	Node* node35 = new Node(35);
	Node* node25 = new Node(25);
	Node* node37 = new Node(37);
	Node* node60 = new Node(61);
	Node* node55 = new Node(55);

	node40->left = node20;
	node40->right = node50;
	node20->left = node10;
	node20->right = node35;
	node35->left = node25;
	node35->right = node37;
	node50->right = node60;
	node60->left = node55;

	root = node40;
    printTree(root,0);
	splittree(root , 35);

	cout<<"root of left trees : ";
	for(int i=0 ; i<l.size() ; i++){
		cout<<l[i]->val<<" ";
	}
	cout<<endl;

	cout<<"root of right trees : ";
	for(int i=0 ; i<r.size() ; i++){
		cout<<r[i]->val<<" ";
	}
	cout<<endl;


	Node* ltree = leftMerge(l);
	Node* rtree = rightMerge(r);

	cout<<"Inorder traversal Left tree after spliting : "<<endl;
	printTree(ltree,0);
	cout<<endl;
	cout<<"Inorder traversal Right tree spliting : "<<endl;
	printTree(rtree,0);
}
