#include<stdio.h>
int fact(int);
void main(){
int n,r;
printf("Enter the number - ");
scanf("%d",&n);
r=fact(n);
printf("factorial no - %d",r);
}
int fact(int n){
if(n==1)
    return 1;
    else
        return (n*fact(n-1));
}
