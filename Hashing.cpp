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

class HashTable{
private:
    static const int size = 10;
    Node* table[size];

public:
    HashTable(){
        for(int i=0; i<size; i++){
            table[i] = NULL;
        }
    }

    int hashFunction(int key){
        return key % size;
    }

    void insert(int val){
        int index = hashFunction(val);
        Node* newNode = new Node(val);

        if(table[index] == NULL){
            table[index] = newNode;
        }
        else{
            Node* temp = table[index];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout<<"Value inserted at index "<<index<<endl;
    }

    void search(int val){
        int index = hashFunction(val);
        Node* temp = table[index];

        while(temp != NULL){
            if(temp->data == val){
                cout<<"Value found at index "<<index<<endl;
                return;
            }
            temp = temp->next;
        }

        cout<<"Value not found\n";
    }

    void deleteValue(int val){
        int index = hashFunction(val);
        Node* temp = table[index];
        Node* prev = NULL;

        while(temp != NULL){
            if(temp->data == val){
                if(prev == NULL){
                    table[index] = temp->next;
                }
                else{
                    prev->next = temp->next;
                }

                delete temp;
                cout<<"Value deleted\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout<<"Value not found\n";
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<"Index "<<i<<": ";
            Node* temp = table[i];

            while(temp != NULL){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main(){
    HashTable ht;
    int choice, val;

    while(true){
        cout<<"\n===== HASH MENU =====\n";
        cout<<"1. Insert\n";
        cout<<"2. Search\n";
        cout<<"3. Delete\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>val;
                ht.insert(val);
                break;

            case 2:
                cout<<"Enter value: ";
                cin>>val;
                ht.search(val);
                break;

            case 3:
                cout<<"Enter value: ";
                cin>>val;
                ht.deleteValue(val);
                break;

            case 4:
                ht.display();
                break;

            case 5:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}
