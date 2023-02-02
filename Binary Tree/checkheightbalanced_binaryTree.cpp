#include<iostream>
using namespace std;
// for each node, the difference between the highest
// of the left subtree and right subtree <=1
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

int calcheight(Node* root){
    if(root==NULL) return 0;
    return max(calcheight(root->left),calcheight(root->right))+1;
}
//not optimised, time complexity --> O(n*n)
bool isBalanced(Node* root){
    if(root==NULL){
        return true; //if empty node, then consider as true
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    
    int lh = calcheight(root->left);
    int rh = calcheight(root->right);
    if(abs(lh-rh)<=1) return true;
    else return false;
}
//optimised, time complexity --> O(n)
bool isBalanced_opt(Node* root, int* height){
    if(root==NULL) return true; //empty balanced tree
    
    int lh=0,rh=0;
    if(isBalanced_opt(root->left,&lh)==false){
        return false;
    }
    if(isBalanced_opt(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    } else {
        return false;
    }

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
    // root->right->right->right = new Node(8);
    // root->right->right->right = new Node(9);
    // root->right->right->right->right = new Node(10);

    if(isBalanced(root)){
        cout<<"Balanced tree"<<endl;
    } else cout<<"Not Balanced tree"<<endl;

    int height=0;
    
    if(isBalanced_opt(root,&height)){
        cout<<"opt --> Balanced tree"<<endl;
    } else cout<<"opt --> Not Balanced tree"<<endl;
    return 0;
}