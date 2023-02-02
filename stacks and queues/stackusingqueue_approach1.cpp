#include<iostream>
#include<queue>
using namespace std;

class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack(){
        n=0;
    }

    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){  //from this, we get the reverse of q1
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop(){
        if(q1.empty()){
            cout<<"No element to pop"<<endl;
            return;
        }
        q1.pop();
        n--;
    }
    int top(){
        if(q1.empty()){
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return q1.front();
    }
    int size(){
        return n;
    }

};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    
    return 0;
}