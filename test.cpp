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

int largest(int arr[], int n,int start)
{
    int i;
    int max = arr[start];
    for (i = start; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

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

    int leftRemaining = largest(a,mid-l+1,l);
    int rightRemaining = largest(a,r+1,mid+1);
    cout<<"\n" << leftRemaining<<" - "<<rightRemaining<<"\n";
	// int leftRemaining = prefixsum[mid] - (l-1>=0 ? prefixsum[l-1] : 0);
	//int rightRemaining = prefixsum[r] - (mid>=0 ? prefixsum[mid] : 0 );
	newnode->left = helper(l , mid  , leftRemaining  , a , prefixsum);
	newnode->right = helper(mid+1 , r , rightRemaining , a , prefixsum);

	return newnode;

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

	return max(l,r);

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
		sum = max(a[i],sum);
		//i==0 ? prefixsum[i] = a[i] : prefixsum[i] = max(a[i],largest(prefixsum,prefixsum.size(),0));
	}


	for(int i=0 ; i<n ; i++){
		cout<<prefixsum[i]<<" ";
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
