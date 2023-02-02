#include<iostream>
using namespace std;

void countSort(int arr[], int n){
    int k = arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main()
{
    int arr[]={1,6,1,4,7,2,9,2};
    countSort(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    return 0;
}