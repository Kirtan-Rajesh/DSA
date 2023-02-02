#include<stdio.h>
void insert_sort(int n, int arr[]){
    for(int i=0;i<n;i++){
        int j=i-1;
        int a = arr[i];
        while(arr[j]>a && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=a;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insert_sort(n,arr);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}


