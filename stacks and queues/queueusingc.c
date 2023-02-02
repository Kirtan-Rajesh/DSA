#include<stdio.h>
#include<stdbool.h>
#define n 100
int queue[n];
int front=-1, back=-1;

void push_elem(int val){
    if(front==-1){
        front++;
    }
    queue[++back]=val;
}
void pop(){
    if(front==-1 || front>back){
        printf("No elements to pop\n");
        return;
    }
    front++;
}
int peek(){
    if(front==-1 || front>back){
        printf("No elements to peek\n");
        return -1;
    }
    return queue[front];
}
bool empty(){
    if(front==-1 || front>back){
        return true;
    }
    return false;
}

int main(){
    push_elem(1);
    push_elem(2);
    push_elem(3);
    push_elem(4);
    push_elem(5);
    printf("%d\n",peek());
    pop();
    printf("%d\n",peek());
    pop();
    printf("%d\n",peek());
    pop();
    printf("%d\n",peek());
    pop();
    printf("%d\n",peek());
    pop();
    printf("%d\n",peek());
    pop();
    
    return 0;
}