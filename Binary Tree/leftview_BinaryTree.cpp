#include<iostream>
#include<queue>
using namespace std;
// seeing the binary tree from left side
//like wind will blow on which nodes if if blows leftways
/*         5
        3     6
      2   4   
*/
//ans - 5 3 2
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
//time complexity --> O(n)
void leftView(Node* root){
    if(root==NULL) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();

            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    // right view
    leftView(root);
    return 0;
}