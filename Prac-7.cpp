#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node *par;

    Node(int value, Node *parent){
        val = value;
        par = parent;
        left = NULL;
        right = NULL;
    }
};

void insert_ele(int ele, Node *cur){
    // cout << "hi" << endl;
    int add = ele;
    while(1){
        // cout << cur -> val << endl;
        if(cur -> val > add){
            swap(cur -> val, add);
        }
        if(cur -> left == NULL){
            break;
        }
        cur = cur -> left;
    }

    Node *newnode = new Node(add, cur);
    cur -> left = newnode;
    // cout << "hi" << endl;
}

void delete_ele(Node *cur){
    // cout << cur -> val << endl;
    Node *par = cur;
    if(cur -> left == NULL && cur -> right == NULL){
        cur = NULL;
        return;
    }

    if(cur -> left == NULL){
        swap(cur -> val, cur -> right -> val);
        cur = cur -> right;
    }
    else if(cur -> right == NULL){
        swap(cur -> val, cur -> left -> val);
        cur = cur -> left;
    }
    else{
        if(cur -> left -> val <= cur -> right -> val){
            swap(cur -> val, cur -> left -> val);
            cur = cur -> left;
        }
        else{
            swap(cur -> val, cur -> right -> val);
            cur = cur -> right;
        }
    }

    while(1){
        if(cur -> left == NULL && cur -> right == NULL){
            // cout << cur -> val << endl;
            // delete cur;
            if(par -> left == cur) par -> left = NULL;
            else par -> right = NULL;
            break;
        }
        if(cur -> left == NULL){
            swap(cur -> val, cur -> right -> val);
            par = cur;
            cur = cur -> right;
        }
        else if(cur -> right == NULL){
            swap(cur -> val, cur -> left -> val);
            par = cur;
            cur = cur -> left;
        }
        else{
            if(cur -> left -> val <= cur -> right -> val){
                swap(cur -> val, cur -> left -> val);
                par = cur;
                cur = cur -> left;
            }
            else{
                swap(cur -> val, cur -> right -> val);
                par = cur;
                cur = cur -> right;
            }
        }
    }
}

int main(){
    Node *newnode10 = new Node(10, NULL);
    Node *newnode20 = new Node(20, newnode10);
    newnode10 -> left = newnode20;
    Node *newnode30 = new Node(30, newnode10);
    newnode10 -> right = newnode30;
    Node *newnode40 = new Node(40, newnode20);
    newnode20 -> left = newnode30;
    Node *newnode50 = new Node(50, newnode20);
    newnode20 -> right = newnode50;
    Node *newnode60 = new Node(60, newnode30);
    newnode30 -> left = newnode60;
    Node *newnode70 = new Node(70, newnode30);
    newnode30 -> right = newnode70;

    Node *root = newnode10;
    while(1){
        int choice;
        cout << "Enter an option" << endl;
        cout << "1. Insert element to min heap" << endl;
        cout << "2. Delete min element" << endl;
        cout << "3. Print min element" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;
        if(choice == 1){
            int ele;
            cout << "Enter an element you want to add" << endl;
            cin >> ele;

            insert_ele(ele, root);
        }
        else if(choice == 2){
            delete_ele(root);
        }
        else if(choice == 3){
            cout << root -> val << endl;
        }
        else{
            break;
        }

    }

    return 0;
}
