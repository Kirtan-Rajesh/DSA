#include<stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        int j = i-1;
        int a = arr[j];
        int pos=0;
        for(int k=1;k<n-1;i++){
            if(a>arr[k-1] && a<arr[k]){
                pos = k-1;
                int k=n-1;
                while(k>=pos){
                    arr[k]=arr[k-1];
                    k--;
                }
                arr[k]=a;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }    
    return 0;
}