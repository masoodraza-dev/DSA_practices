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
// This findMin method helper method to delete a node from Binary Search Tree
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root , int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data){
        root->left = deleteNode(root->left , key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right , key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right , temp->data);
        }
    }
    return root;
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
    insert(root,11);

    search(root , 12);
    search(root , 13);

    cout<< "Before deletion:";

    cout<<"\n in order"<<endl; 
    inorder(root);

    deleteNode(root , 11);
    cout<< "After deletion:";

    cout<<"\n in order"<<endl; 
    inorder(root);

    cout<<"pre order"<<endl;
    preorder(root);

    cout<<"\n post order"<<endl;
    postorder(root);

    
}
