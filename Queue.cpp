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

class Queue{
    private:
        Node* front;
        Node* rare;

    public:
        Queue() {
            front = rare = NULL;
        }

    void enqueue (int val){
        Node* newNode = new Node(val);
        if(front == NULL){
            front = rare = newNode;
            return;
        }

        Node* temp = front;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
        // rare->next = newNode;   // direct add from rear.
        // rare = newNode;
        cout<<"a value added in a queue "<<endl;
    }

    void dequeue(){
        if(front == NULL){
            cout<<"The queue is empty: " << endl;
            return;
        }

        Node* temp = front;
        front = front ->next;
        temp->next = NULL;
        cout<< "The Value" << temp->data << " is deleted from the queue: "<<endl;
        delete temp;
    }

    void displayQueue(){
        if(front ==NULL){
            cout<<"The queue is empty: \n";
            return;
        }

        Node* temp = front;
        while(temp != NULL){
            cout<< temp->data << " ";
            temp= temp->next;
        }
    }

    void frontValue(){
        if(front==NULL){
            cout<<"The queue is empty: \n";
            return;
        }
        cout<<"The front is: " << front->data <<endl;
    }
};


int main(){
    Queue qu;

   int choice, val;

while (true) {

    cout << "\n===== QUEUE MENU =====\n";
    cout << "1. Enqueue (Add Number)\n";
    cout << "2. Dequeue (Remove Number)\n";
    cout << "3. Display\n"; 
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter a number to add: ";
            cin >> val;
            qu.enqueue(val);
            break;

        case 2:
            qu.dequeue();
            break;

        case 3:
            qu.displayQueue();
            break;    

        case 4:
            cout << "Exited successfully\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
    }
}
}
