#include<stdio.h>
int fibo(int);
void main()
{
   int n,c,i=0;
   printf("Enter a number - ");
   scanf("%d",&n);
   printf("Fibonics  series \n");
   for( c=0;c<n;c++){
    printf("%d",fibo(i));
    i=i+1;

   }

}
int fibo(int n){
if(n==0)
    return 0;
    else if(n==1)
        return 1;
    else
        return fibo(n-1)+(n-2);
}
