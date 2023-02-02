#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
/*         1
        2     3
      4  5  6   7
*/
// preOrder ->  start from root, go to left substree,
// print all left node first, then go to right nodes of the subtree
// after completing the left subtree, go to right subtree and do the same as above
void preOrder(struct Node* root){
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
// inOrder ->  Start from end of the left substree,
// print all left node first from down to up (do not go to root yet),
// then go to right nodes of the subtree
// after completing the left subtree, go to root
// and then go to right subtree and do the same as above
void inOrder(struct Node* root){
    if(root==NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//postOrder ->  start from end of the left substree,
// print all nodes of lowest level first from left to right
// then go to above levels (don't go to root yet)
// after printing left subtree,  go to right subtree and do the same
void postOrder(struct Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    struct Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    return 0;
}