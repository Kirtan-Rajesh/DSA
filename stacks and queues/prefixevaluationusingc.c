#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

// one way
// int main(){
//     char s[]="-+7*45+20";
//     int n=strlen(s);
//     int stack[n],top=-1;
//     for(int i=n-1;i>=0;i--){
//         if(s[i]>='0' && s[i]<='9'){
//             stack[++top]=s[i]-48;
//         } else {
//             int op1 = stack[top--];
//             int op2 = stack[top--];
//             switch(s[i]){
//                 case '+': stack[++top]=op1+op2;break;
//                 case '-': stack[++top]=op1-op2;break;
//                 case '*': stack[++top]=op1*op2;break;
//                 case '/': stack[++top]=op2/op1;break;
//             }
//         }
//     }
//     printf("%d",stack[0]);
//     return 0;
// }

//other  way
struct Stack{
    int top;
    unsigned capacity;
    int* array;
}
Stack* createStack(unsigned cap){
    
}
int main(){

    return 0;
}