#include<stdio.h>
void select_sort(int n, int arr[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
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
    select_sort(n,arr);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}


