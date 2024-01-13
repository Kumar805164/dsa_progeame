// assignment 4 (a) i , ii complete , concept of LIFO in stack
#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int top = -1,inp_array[SIZE];
void push();
void pop();
void show();

int main(){
int ch;

while(1)
{

    printf("\n      Perform operation on the stack :- ");
    printf("\n****************************************** ");
    printf("\n 1. Pus the element       2. Pop the element  \n 3. Show                     4.End\n");
    printf("****************************************** ");
    printf("\n Enter the choice : -  ");
   scanf("%d",&ch);

   switch(ch)
   {

   case 1:
        push();
        break;
   case 2:
    pop();
    break;
   case 3:
    show();
    break;
   case 4:
    exit(0);
   default:
    printf("\n Invalid choice");
   }

}
}

void push(){
int x;
if(top == SIZE-1){
    printf("\n OverFlow !!");
}else{
printf("Enter the element to be added onto the stack :");
scanf("%d",&x);
printf("\n-----------------------------------------------");
top=top+1;
inp_array[top]=x;
}
}

void pop(){
if (top == -1){
    printf("\nUnderFlow!!");
}
else{
    printf("Popped element : %d",inp_array[top]);
    printf("\n-----------------------------------------------");
    top=top-1;
}
}
void show(){
int i;
if(top == -1){
    printf("\n UnderFlow !!");
}
else{
    printf("\nElement present in the stack\n");
    printf("--------------------------------------------");

    for(i=top;i>=0;i--){

        printf("\n%d\n",inp_array[i]);
    }
}
}
