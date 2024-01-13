#include<stdio.h>
#include<stdlib.h>
int main()
{
	int item,i=0,f=0;
	int a[5]={39,24,55,42,11};
	printf("enter the searching item :");
	scanf("%d",&item);
	while(i<5)
	{
    		if(a[i]==item)
    		{

        		f=1;
    		}
    		++i;
	}

	if(f==1)
	{
    		printf("item found at %d",i);

	}
	else
	{
		printf("item not found");
	}
	return 0;
}
