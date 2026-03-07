#include<iostream>
using namespace std ;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
         List(){
             head=tail= NULL;
         }

    void pushFront(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            newNode->next=head;
            head = newNode;
        }
        cout<<"Value added successfully"<<endl;
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head == NULL){ 
            head = tail = newNode;
        }else{
            tail->next=newNode;
            tail = newNode;
        }
        cout<<"Value added successfully"<<endl;
    }

    void printLL(){
        Node* temp = head;
        if(temp==NULL){
            cout<<"The Linked List is Null"<<endl;
            return;
        }
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    bool search(int value){
        Node* temp = head;

        while(temp != NULL){
            if(temp->data == value){
                cout<<"value found";
                return true;
            }else{
                temp = temp->next;
            }
            
        }
        cout<<"value not found";
        return false;
    }

    void RemoveEnd(){
        if (head == NULL){
            cout<<"Linked List is null \n";
            return ;
        }

        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        Node* prev = temp;
        temp = prev->next;
        prev->next = NULL;
        delete temp;

        // Node* del = temp->next; --> loop se jb bahr aaega to temp 2nd last node hoga or last node temp ka next hoga 
        // temp->next = NULL;  --> temp 2nd last node he uski next ko kr dia (ab temp last node bn gya)
        // delete del;

        cout<<" the last Node deleted ";
    }

    // void delet(int val){
    //     if(head==NULL){
    //         cout<<"The list is null"<<endl;
    //         return;
    //     }
    //     Node* cur = head;
    //     Node* prev = NULL;

    //     if(head == val){
    //         head = head->next;
    //         cur ->next = NULL;
    //         free(cur);
    //     }
    //     while(cur->data !=NULL){
    //         if(cur->data == val){
    //             prev->next = cur->next;
    //             free(cur);
    //             return;
    //         }else{
    //             prev = cur;
    //             cur = cur ->next;
    //         }
    //     }
    // }
};

int main(){
    List ll;
    ll.printLL();
    ll.pushBack(4);
    ll.pushBack(14);
    ll.pushBack(41);
    ll.pushFront(6);
    ll.pushFront(69);
    ll.pushFront(96);
    ll.printLL();
    ll.search(69);

    

    return 0;
}
