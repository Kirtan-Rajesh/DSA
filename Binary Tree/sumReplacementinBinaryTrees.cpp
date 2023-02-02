#include<iostream>
using namespace std;
/*         1
        2     3
      4  5   6  7
*/
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
void sumReplace(Node* root){

    if(root==NULL){
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left!=NULL){
        root->data += root->left->data;
    }
    if(root->right!=NULL){
        root->data += root->right->data;
    }
}
void preOrderPrint(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //sum replacement
    preOrderPrint(root);
    cout<<endl;
    sumReplace(root);
    preOrderPrint(root);
    cout<<endl;

    return 0;
}