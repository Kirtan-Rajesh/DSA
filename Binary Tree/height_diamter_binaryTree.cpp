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
int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = calcHeight(root->left);
    int rheight=calcHeight(root->right);
    return max(lheight,rheight)+1;
}
// not optimised --> time complexity O(n*n)
int calcDiameter(Node* root){
    if(root==NULL) return 0;
    int lheight=calcHeight(root->left);
    int rheight=calcHeight(root->right);
    int currDiameter=lheight+rheight+1;

    int ldiameter= calcDiameter(root->left);
    int rdiameter= calcDiameter(root->right);
    return max(currDiameter,max(ldiameter,rdiameter));
}
// optimised --> time complexity O(n)
int calcDiameter_opt(Node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0, rh=0;
    int ldiameter=calcDiameter_opt(root->left,&lh);
    int rdiameter=calcDiameter_opt(root->right,&rh);

    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currDiameter, max(ldiameter,rdiameter));

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

    cout<<calcHeight(root)<<endl;
    cout<<calcDiameter(root)<<endl;

    int height=0;
    cout<<calcDiameter_opt(root, &height)<<endl;
    return 0;
}