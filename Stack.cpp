#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class stack{
    private:
        Node* top;

    public:
    stack(){
        top = NULL;
    }

    void pushStack(int val){
        Node* newNode = new Node(val);
        if(top ==NULL){
            top=newNode;
            return;
        }
        
        newNode->next = top;
        top = newNode;

    }

    void popStack(){
        
        if(top == NULL){
            cout<< "The stack is empty: " << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        temp->next =NULL;
        cout<< "value "<< temp->data <<" is poped:\n";
        delete temp;
       
    }

    void showStack(){
        if(top==NULL){
            cout<<"stack is empty:";
            return;
        }

        Node* temp = top;
        while(temp != NULL){
            cout << "->" << temp->data <<endl;
            temp=temp->next;
        }

        
    }

    void topOfStack(){
        cout<< top->data <<" is at the top of stack:" <<endl;
    }
};

int main(){
    stack list;

    list.pushStack(40);
    list.pushStack(30);
    list.pushStack(20);
    list.pushStack(10);

    list.showStack();

    list.popStack();

    list.showStack();
 return 0;
}
