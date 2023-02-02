#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;

}
void insertAtMiddle(node* &head, int val, int pos){
    node* temp = head;
    node* n = new node(val);
    int count=1;
    while(temp->next!=head && count<pos-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next=n;
}
void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    head=temp->next;
    delete todelete;
}
void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(count<pos){
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
//Put Even Position Nodes after Odd Position Nodes
void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}
void display(node* &head){
    node* temp=head;
    do{
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<"NULL"<<endl;
}
int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,6);
    insertAtHead(head,7);
    display(head);
    insertAtMiddle(head,10,3);
    // display(head);
    // deletion(head,1);
    // display(head);
    // deletion(head,4);
    // display(head);
    evenAfterOdd(head);
    display(head);
    return 0;
}