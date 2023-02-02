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

Node* constructBST(int preOrder[], int* preOrderIdx, int key, int min, int max, int n){
    if(*preOrderIdx >= n){
        return NULL;
    }
    
    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preOrderIdx = *preOrderIdx + 1;

        if(*preOrderIdx<n){
            root->left = constructBST(preOrder,preOrderIdx,preOrder[*preOrderIdx],min,key,n);
        }
        if(*preOrderIdx<n){
            root->right = constructBST(preOrder,preOrderIdx,preOrder[*preOrderIdx],key,max,n);
        }
    }
    return root;
}
void printPreorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main()
{
    /*       10
            / \
           2   13
          /   /
         1   11
    */
    int preOrder[] = {10,2,1,13,11};
    int n = 5;
    int preOrderIdx = 0;
    Node* root = constructBST(preOrder, &preOrderIdx,preOrder[0],INT_MIN, INT_MAX,n);
    printPreorder(root);
    return 0;
} 