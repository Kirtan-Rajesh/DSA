#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int n){
        data=n;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* temp = new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
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
void insertAtMiddle(node* &head, int aftval, int val){
    node* n = new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* temp1 = head;
    while(temp1->data!=aftval){
        temp1=temp1->next;
    }
    node* temp2 = temp1->next;
    temp1->next=n;
    n->next=temp2;
}

bool search(node* &head, int val){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deleteAtHead(node* &head){
    node* todelete = head;
    head=head->next;
    delete todelete; 
}
void deletion(node* &head, int val){  //any node
    if(head==NULL) return;
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        if(temp->next==NULL){
            cout<<temp->data<<" -> NULL"<<endl;
        } else cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;    
}

//reverse k nodes
node* reversek(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL) head->next=reversek(nextptr,k);
    return prevptr;
}
//make a cycle in a linked list
void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

//detection of a cycle in a linked
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
//removing a cycle after detecting a cycle
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}
void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2 =head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    node* temp1;
    node* temp2;
    int d=0;
    if(l1>l2){
        d=l1-l2;
        temp1=head1;
        temp2=head2;        
    } else {
        d=l2-l1;
        temp1=head2;
        temp2=head1;
    }
    while(d--){
        temp1=temp1->next;
        if(temp1==NULL) return -1;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}
node* mergeLL(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode= new node(-1);
    node* p3 = dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        } else {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while (p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;        
    }
    while (p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;        
    }
    return dummyNode->next;    
}

node* mergeRecursive(node* &head1, node* &head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next, head2);
    } else {
        result = head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}
int main()
{
    // node* head = NULL;
    // insertAtHead(head,1);
    // insertAtHead(head,2);
    // insertAtTail(head,9);
    // insertAtTail(head,8);
    // insertAtHead(head,5);
    // insertAtMiddle(head,2,11);
    // display(head);
    // node* newrevhead = reversek(head,2);
    // display(newrevhead);
    // deleteAtHead(head);
    // deleteAtHead(head);
    // deletion(head,9);
    // display(head);
    // node* newhead = reverse(head);
    // display(newhead);
    
    node* head1 = NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head1,7);
    insertAtTail(head1,8);
    display(head1);

    node* head2 = NULL;
    insertAtTail(head2,8);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    insertAtTail(head2,11);
    display(head2);
    
    node* newhead = mergeRecursive(head1,head2);
    display(newhead);
    // intersect(head2,head1,3);
    // cout<<intersection(head1,head2)<<endl;
    // makeCycle(head,3);
    // //display(head);
    // cout<<boolalpha<<detectCycle(head)<<endl;
    // removeCycle(head);
    // display(head);
    // node* newhead = kappend(head,3);
    // display(newhead);


    return 0;
}