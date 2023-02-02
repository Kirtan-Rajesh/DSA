// heaps are Binary Tree based Data structure
// but not necessarily BST
// two types -> MinHeap, MaxHeap
// MaxHeap -> root > rest of elements present in subtree
// MinHeap -> root < rest of elements present in subtree
// when we swap elements of a binary tree, this mehtod is called heapify

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>
using namespace std;
int main()
{
    //maxHeap
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(4);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    //minHeap
    priority_queue<int,vector<int>,greater<int>> pqm;
    pqm.push(5);
    pqm.push(2);
    pqm.push(3);
    pqm.push(4);
    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;
    
    return 0;
}