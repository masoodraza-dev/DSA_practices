#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root , int value){
    if(root == NULL){
        return new Node(value);
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root , int key){
    if(root == NULL){
        cout<< "not found: "<< endl;
        return false;
    }

    if(root->data == key){
        cout<< "The value found:"<<endl;
        return true;
    }

    if(root->data < key ){
        return search(root->right , key);
    }else{
        return search(root->left , key);
    }
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void postorder(Node* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;

    root = insert(root,50);
    insert(root,40);
    insert(root,12);
    insert(root,67);

    search(root,12);
    search(root,11);

    cout<<"pre order"<<endl;
    preorder(root);

    cout<<"\n post order"<<endl;
    postorder(root);

    cout<<"\n in order"<<endl; 
    inorder(root);
}
