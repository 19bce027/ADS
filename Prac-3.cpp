#include<bits/stdc++.h>
using namespace std;

class Node{
	public :
	Node *left , *right , *parent;
	int key;
	int obj;

	Node(){
		left = NULL;
		right = NULL;
		parent = NULL;
		key = 0;
		obj = 0;
	}
	Node(int val){
		left = NULL;
		right = NULL;
		parent = NULL;
		key = val;
		obj = 0;
	}
};

class Tree{
	public:

		Node* root = NULL;
		int dep;
		int n = 0;
		vector<int>arr;

		int getSize(Node* root){
			if(root==NULL){
				return 0;
			}

			int l = getSize(root->left);
			int r = getSize(root->right);

			return 1 + l + r;
		}

		int insertHelper(Node* newnode , Node* par ){
			if(par==NULL){
				root = newnode;
				return 1;
			}

			if(par->key > newnode->key){
				dep ++;
				if(par->left == NULL){
					newnode->parent = par;
					par -> left = newnode;
					return 1;
				}

				insertHelper(newnode, par -> left);
			}
			else if(par -> key < newnode -> key){
				dep ++;
				if(par -> right == NULL){
					newnode -> parent = par;
					par -> right = newnode;
					return 1;
				}

				insertHelper(newnode, par -> right);
			}else{
				return -1;
			}
		}

		void makearray(Node* root){
			if(root == NULL){
				return;
			}

			arr.push_back(root->key);
			makearray(root->left);
			makearray(root->right);
		}
		Node* reShuffleTree(int l , int r , vector<int>&arr){

			if(l > r){
				return NULL;
			}
			int mid = l + (r-l)/2;

			Node* newnode = new Node(arr[mid]);

			newnode->left = reShuffleTree(l , mid-1 , arr);
			newnode->right = reShuffleTree(mid+1 , r , arr);

			return newnode;

		}
		bool terminate = 0;

		void findScapeGoat (Node* root){

			if(root->parent == NULL || terminate == 1){
				return;
			}

			int x = getSize(root);
			int y = getSize(root->parent);

			if(x > (((2*1.0)/(3*1.0))*y)){
				terminate = 1;
				Node* par = root->parent->parent;
				Node* curr = root->parent;

				makearray(curr);
				sort(arr.begin() , arr.end());

				Node* rootForShuffledTree = reShuffleTree(0 , arr.size()-1 , arr);

				if(par->left == curr){
					par->left = rootForShuffledTree;
				}else if(par->right == curr){
					par->right = rootForShuffledTree;
				}
			}

			findScapeGoat(root->parent);

		}

		int insert(int val){
			Node* newnode = new Node(val);
			dep = 0;
			int done = insertHelper(newnode , root );
			if(done == -1){
				cout << "The entered key is a duplicate value" << endl;
			}
			else {
				n++;
			}

			if((dep*1.0) > ((1.0*log10(n*1.0)) / (1.0*log10(1.5)))){
				findScapeGoat(newnode);
			}
			return dep;
	    }

	    void preorder(Node* cur){
	    	if(cur != NULL){
	    		cout << cur -> key << " ";
	    		preorder(cur -> left);
				preorder(cur -> right);
			}
		}
};

int main(){
	Tree var;

	string line;
	ifstream input_file("data_3.txt");
  	while (getline (input_file, line)) {
  		int x = stoi(line);
		var.insert(x);
	}

    cout << "Pre order : " ;
	var.preorder(var.root);
}
