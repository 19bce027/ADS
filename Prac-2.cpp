#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

class Node {
   public:
    int key;
    int object;
    Node *left;
    Node *right;
    int height;
};

Node *root;
int max(int a, int b);

int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

Node *newNode(int key,int object) {
  Node *node = new Node();
  node->key = key;
  node->object = object;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

Node *rrotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),height(y->right)) + 1;
  x->height = max(height(x->left),height(x->right)) + 1;
  return x;
}

Node *lrotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),height(x->right)) + 1;
  y->height = max(height(y->left),height(y->right)) + 1;
  return y;
}


int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

Node *insertNode(Node *node, int key,int object) {
  if (node == NULL)
    return (newNode(key,object));
  if (key < node->key)
    node->left = insertNode(node->left, key,object);
  else if (key > node->key)
    node->right = insertNode(node->right, key,object);
  else
    return node;

  node->height = 1 + max(height(node->left),height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rrotate(node);
    } else if (key > node->left->key) {
      node->left = lrotate(node->left);
      return rrotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return lrotate(node);
    } else if (key < node->right->key) {
      node->right = rrotate(node->right);
      return lrotate(node);
    }
  }
  return node;
}

void create()
{
    root=NULL;
    ifstream datafile("data.txt");
    string line="";
    while (getline (datafile, line)) {
        vector <string> tokens;
        stringstream check1(line);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
        root = insertNode(root,stoi(tokens[0]),stoi(tokens[1]));
    }
    datafile.close();
}

Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *deleteNode(Node *root, int key) {
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left),height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rrotate(root);
    } else {
      root->left = lrotate(root->left);
      return rrotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return lrotate(root);
    } else {
      root->right = rrotate(root->right);
      return lrotate(root);
    }
  }
  return root;
}

void printTree(Node *root) {
    queue <Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
        auto p=q.front();
        q.pop();
        cout<<"key: "<<p->key<<", balance factor: "<<getBalanceFactor(p)<<"  ";
        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
        }
        cout<<endl;
    }
}

int main(){

    int c;
    create();
    do{
        cout<<"-----MENU-----\n";
        cout<<"\n1.Insertion";
        cout<<"\n2.Display";
        cout<<"\n3.Deletion";
        cout<<"\n4.Exit";
        cout<<"\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
            int x,y;
            cout<<"Enter Key and Object to insert : "<<endl;
            cin>>x>>y;
            root = insertNode(root,x,y);
            break;
        case 2:
            printTree(root);
            break;
        case 3:
            cout<<"\nEnter key to delete : ";
            cin>>x;
            root = deleteNode(root,x);
            break;
        case 4:
            break;
        }

     } while(c!=4);

    return 0;
}
