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
Node* inOrderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

// there are three cases while deleting a node
// case 1 -> if the node is a lead node
// case 2 -> if the node has one child
// case 3 -> if the node has two child
Node* deleteInBST(Node* root,int key){
    // key is the value of node to be deleted
    if(key < root->data){
        root->left = deleteInBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right,key);
    }
    else {
        //case 1 and 2
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //case 3
        Node* temp = inOrderSucc(root->left);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}
void inOrderPrint(Node* root){
    if(root==NULL) return;
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}
int main()
{
    /*      4
           / \
          2   5
         / \   \
        1   3   6
    */
    Node* root = new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->left=new Node(3);
    root->right->right=new Node(6);
    inOrderPrint(root);
    cout<<endl;
    deleteInBST(root,5);
    inOrderPrint(root);
    cout<<endl;
    return 0;
}