#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char str[]="{([])}";
    int n=strlen(str);
    bool check=1;
    char stack[n],top=-1;
    for(int i=0;i<n;i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            stack[++top]=str[i];
        } 
        else if(str[i]==')'){
            if(top!=-1 && stack[top]=='('){
                top--;
            } else {
                printf("Not a balanced parenthesis");
                check=0;
                break;
            }
        }
        else if(str[i]==']'){
            if(top!=-1 && stack[top]=='['){
                top--;
            } else {
                printf("Not a balanced parenthesis");
                check=0;
                break;
            }
        }
        else if(str[i]=='}'){
            if(top!=-1 && stack[top]=='{'){
                top--;
            } else {
                printf("Not a balanced parenthesis");
                check=0;
                break;
            }
        }
    }
    if(check) printf("Is a balanced parenthesis");
    return 0;
}