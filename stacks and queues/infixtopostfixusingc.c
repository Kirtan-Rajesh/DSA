#include<stdio.h>
#include<ctype.h>
#include<string.h>
int prec(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}
int main(){
    char str[] = "(a-b/c)*(a/k-l)";
    int n=strlen(str);
    char stack[n], res[n];
    int top=-1, ct=-1;
    for(int i=0;i<n;i++){
        if(isalpha(str[i])){
            res[++ct]=str[i];
        }
        else if(str[i]=='('){
            stack[++top]=str[i];
        }
        else if(str[i]==')'){
            while(top!=-1 && stack[top]!='('){
                res[++ct]=stack[top--];
            }
            if(top!=-1){
                top--;
            }
        }
        else {
            while(top!=-1 && prec(stack[top])>=prec(str[i])){
                res[++ct]=stack[top--];
            }
            stack[++top]=str[i];
        }
    }
    while(top!=-1){
        res[++ct]=stack[top--];
    }
    for(int i=0;i<=ct;i++){
        printf("%c",res[i]);
    }
    return 0;
}