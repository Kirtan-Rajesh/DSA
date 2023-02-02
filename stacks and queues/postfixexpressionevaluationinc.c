#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int main(){
    char s[]="46+2/5*7+";
    int n=strlen(s);
    int stack[n+1],top=-1;
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            stack[++top]=s[i]-48;
        } else {
            int op1 = stack[top--];
            int op2 = stack[top--];
            switch(s[i]){
                case '+': stack[++top]=op1+op2;break;
                case '-': stack[++top]=op1-op2;break;
                case '*': stack[++top]=op1*op2;break;
                case '/': stack[++top]=op2/op1;break;
            }
        }
    }
    printf("%d",stack[0]);
    return 0;
}