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
Node* insertBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left=insertBST(root->left,val);
    }
    else {
        // val > root->data
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inOrderprint(Node* root){
    if(root==NULL){
        return;
    }
    inOrderprint(root->left);
    cout<<root->data<<" ";
    inOrderprint(root->right);
}
int main()
{
    // int arr[]={45,15,79,90,10,55,12,20,50};
    Node* root = NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    inOrderprint(root);
    return 0;
}