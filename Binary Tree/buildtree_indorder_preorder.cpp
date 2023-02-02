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
int search(int inOrder[], int start, int end, int curr){
    for(int i=start;i<=end;i++){
        if(inOrder[i]==curr){
            return i;
        }
    }
    return -1;
}
Node* buildTree(int preOrder[], int inOrder[],int start, int end){
    if(start>end) return NULL;
    static int idx=0;

    int curr=inOrder[idx];
    idx++;
    struct Node* node = new Node(curr);

    if(start == end){
        return node;
    }

    int pos = search(inOrder,start,end,curr);
    node->left=buildTree(preOrder,inOrder,start,pos-1);
    node->right=buildTree(preOrder,inOrder,pos+1,end);

    return node;
}
void inOrderPrint(struct Node* root){
    if(root==NULL) return;

    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);

}
int main()
{
    int preOrder[]={1,2,3,4,5};
    int inOrder[]={4,2,1,5,3};

    //build tree
    struct Node* root=buildTree(preOrder,inOrder,0,4);
    inOrderPrint(root);
    return 0;
}