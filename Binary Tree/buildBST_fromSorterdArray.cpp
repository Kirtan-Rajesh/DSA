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

Node* sortedArrayToBST(int arr[], int start, int end){
    // start, end are parts of array
    // which are in consideration for adding into the BST
    if(start>end) return NULL;
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);

    return root;
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
    int arr[]={10,20,30,40,50};
    Node* root = sortedArrayToBST(arr,0,4);
    preOrderPrint(root);
    return 0;
}