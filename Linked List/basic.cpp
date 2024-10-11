#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void InserAtTail (Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtPosition(Node* &head, int position, int d){
    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }

    //Creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void InsertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){
    //created a new node
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    //head pointed to model
    Node* head = node1;
    Node* tail = node1;
    

    // InsertAtHead(head, 12);
    InserAtTail(tail, 11);
    
    InsertAtPosition(head, 2, 12);
    print(head);
    
}