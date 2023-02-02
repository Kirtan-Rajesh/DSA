#include<iostream>
#include<algorithm>
using namespace std;

int BinarySeaarch(int arr[],int start, int end, int key){
    int mid = (start+end)/2;
    if(end>=start){
        if(arr[mid]==key){
            return mid;
        } 
        else if(arr[mid]>key){
            return BinarySeaarch(arr,start,mid-1,key);
        } else {
            return BinarySeaarch(arr,mid+1,end,key);
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
    sort(arr,arr+n);
    int key,index;
    cin>>key;
    index=BinarySeaarch(arr,0,n,key);
    if(index==-1) cout<<"Element not present in  array"<<endl;
    else cout<<"Element present at index: "<<index<<endl;
    
    return 0;
}