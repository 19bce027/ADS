#include<bits/stdc++.h>
using namespace std;
#define COUNT 10

struct Node{
	int lowerBound , upperBound;
	Node* left, *right;
	int val;

	Node(int l , int r , int data){
		lowerBound = l;
		upperBound = r;
		left = right = NULL;
		val = data;
	}
};

Node* root = NULL;

Node* helper(int l , int r , int sum , int a[] , vector<int>prefixsum){
	if(l > r){
		return NULL;
	}

	if(l==r){
		Node* newnode = new Node(l , r , a[l]);
		return newnode;
	}

	Node* newnode = new Node(l , r , sum);

	int mid = (l+r)/2;

	int leftRemaining = prefixsum[mid] - (l-1>=0 ? prefixsum[l-1] : 0);
	int rightRemaining = prefixsum[r] - (mid>=0 ? prefixsum[mid] : 0 );
	newnode->left = helper(l , mid  , leftRemaining  , a , prefixsum);
	newnode->right = helper(mid+1 , r , rightRemaining , a , prefixsum);

	return newnode;

}

void preorder(Node* root){
	if(root == NULL){
		return;
	}

	cout<<root->val <<" "<<root->lowerBound <<" "<<root->upperBound<<endl;
	preorder(root->left);
	preorder(root->right);
}

int rangesum(Node* root , int rangeLeft , int rangeRight){
	int nodeLeft = root->lowerBound;
	int nodeRight = root->upperBound;

	if(nodeLeft >= rangeLeft && nodeRight<=rangeRight){
		return root->val;
	}
	if(nodeRight < rangeLeft || nodeLeft > rangeRight){
		return 0;
	}

	int l = rangesum(root->left , rangeLeft , rangeRight);
	int r = rangesum(root->right , rangeLeft , rangeRight);

	return l + r;

}

void printTree(Node *root,int space){  //for printing bst in tree format

    if(root){
        space+=COUNT;
        printTree(root->right,space);
        for(int i=COUNT ; i<space; i++) cout<<" ";
        cout<<root->val<<"\n";
        printTree(root->left,space);
    }
}

int main(){
	cout<<"Enter the number of elements : ";
	int n;
	cin>>n;

	int a[n];
	int sum = 0;

	vector<int> prefixsum(n);

	cout<<"Enter the elements of the tree : ";
	for(int i=0 ; i<n ; i++){
		cin>>a[i];
		sum += a[i];
		i==0 ? prefixsum[i] = a[i] : prefixsum[i] = a[i] + prefixsum[i-1];
	}

	int l = 0 , r = n-1;

	root = helper(l , r , sum , a , prefixsum);
	cout<<"Preorder of the tree"<<endl;
	printTree(root,0);


	cout<<"Enter the range : ";
	int rangeLeft , rangeRight;
	cin>>rangeLeft>>rangeRight;

	cout<<"Sum : ";
	cout<<rangesum(root  , rangeLeft , rangeRight);


}
