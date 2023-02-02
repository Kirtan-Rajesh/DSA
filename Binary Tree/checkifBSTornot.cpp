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
// time complexity -> O(N)
// check for BST
bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
    if(root==NULL) return true; //if root empty, we assume it to be balanced
    if(min!=NULL &&  root->data <= min->data){
        return false;
    } 
    if(max!=NULL &&  root->data >= max->data){
        return false;
    }
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid and rightValid;
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    /*    1
         / \
        2   3
    */
    if(isBST(root1, NULL,NULL)) cout<<"Valid BST"<<endl;
    else cout<<"Invalid BST"<<endl;
    return 0;
}