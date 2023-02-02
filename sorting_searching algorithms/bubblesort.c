#include<stdio.h>

void bubble_sort(int n, int arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(n,arr);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

