#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};

//treversing data
    void print(Node* &head){
        Node* temp=head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }

    void insertAtHead(Node* &head,int d){
        Node*temp= new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    void insertAtTail(Node* &tail,int d){
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    void insertAtPosition(Node* &head, Node* &tail, int position, int d){
        Node* nodeToInsert=new Node(d);
        if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return ;
    }

    nodeToInsert->next=temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev=temp;
 
    }

int main(){
    Node* node1 = new Node(10);
    Node*head = node1;
    Node*tail = node1;
    print(head);

    insertAtHead(head,11);
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtPosition(head,tail,4,17);
    print(head);
    return 0;
}