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

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

bool search(node* &head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* temp= head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;

    delete todelete; 
}

//iterative way of reversing
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr = currptr;
        currptr=nextptr;
    }
    return prevptr;
}

//recursive way of reversing a llk list
node* reverseRecursive(node* &head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* newhead = reverseRecursive(head->next);
    newhead->next->next=head;
    head->next=NULL;
    return newhead;
}

int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

//append k node at the beginning of the ll
node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==(l-k)){
            newTail=tail;
        }
        if(count==(l-k+1)){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    return newHead;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
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
    insertAtHead(head,7);
    insertAtHead(head,8);
    display(head);
    cout<<search(head,5)<<endl;
    cout<<search(head,10)<<endl;
    deletion(head,3);
    display(head);
    deleteAtHead(head);
    display(head);
    
    node* newHead = reverse(head);
    display(newHead);

    node* newrechead = reverseRecursive(newHead);
    display(newrechead);
    

    return 0;
}