//WAP sort the array element using Merge sort
#include<stdio.h>
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];
        for(i=0;i<n1;i++){
            L[i]=arr[l+i];
        for(j=0;j<n2;j++)
            R[j]=arr[m+1+j];

        i=0;
        j=0;
        j=l;

        while(i<n1&&j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i];
                i++;
            }
            else
            {

                arr[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l,m);

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
    }
    }

    void printArray(int A[],int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d",A[i]);
    printf("\n");
    }

    int main()
    {

        int arr[100],i,n;
        printf("Enter the size o array = ");
        scanf("%d",&n);
        printf("Enter the array element - ");
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("Given array is \n");
        printArray(arr,n);
        mergeSort(arr,0,n-1);
        printf("\nSorted array is \n");
        printArray(arr,n);
    }
}

