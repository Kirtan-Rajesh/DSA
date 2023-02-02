#include<iostream>
using namespace std;

int LinearSearch(int arr[],int key,int length){
    for(int i=0;i<length;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key,index;
    cin>>key;
    index=LinearSearch(arr,key,n);
    if(index==-1) cout<<"Element not present in the list"<<endl;
    else cout<<"Element present at index: "<<index<<endl;
}