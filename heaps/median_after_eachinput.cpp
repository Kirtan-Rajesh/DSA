// tell median after each input using heaps
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x){
    if(pqmin.size()==pqmax.size()){
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }
        if(x<pqmax.top()) pqmax.push(x);
        else pqmin.push(x);
    }
    else{
        //two possible cases
        //case1: size of maxHeap > size of minHeap
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            }else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        //case2: size of maxHeap < size of minHeap
        else {
            if(x <= pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}
double findMedian(){
    if(pqmin.size()==pqmax.size()){
        return (pqmin.top()+pqmax.top())/2.0;
    }
    else if(pqmin.size() > pqmax.size()){
        return pqmax.top();
    }
    else return pqmin.top();
}
int main()
{
    insert(6);
    cout<<findMedian()<<endl;
    insert(1);
    cout<<findMedian()<<endl;
    insert(7);
    cout<<findMedian()<<endl;
    insert(2);
    cout<<findMedian()<<endl;
    insert(8);
    cout<<findMedian()<<endl;
    insert(6);
    cout<<findMedian()<<endl;
    return 0;
} 