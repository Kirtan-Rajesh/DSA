#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
//case 1 - when we have to find distance at the subtree nodes
void printSubtreeNodes(Node* root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

//case 2 - returning the distance of the target node from the ancestors
int printNodeAtk(Node *root, Node* target, int k){
    if(root==NULL){
        return -1;  //we didn't find the target node
    }
    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }

    int dl = printNodeAtk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        } else {
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr = printNodeAtk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        } else {
            printSubtreeNodes(root->left,k-dl-2);
        }
        return 1+dr;
    }
    return -1;
}

int main()
{
    /*      1
           / \
          2   3
         /
        4
    */

    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);

    //test
    printNodeAtk(root,root->left,1);
   

    return 0;
}