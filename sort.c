
#include <stdio.h>
//#include <conio.h>

void sortarray(int* , int);

int main()
{
    int n,a[100],i;
//    clrscr();
    printf("\nEnter the Number of Elements in an array : ");
    scanf("%d",&n);
    printf("\nEnter the Array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
	}

    sortarray(a,n);

    printf("\nAfter Sorting....\n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
	}
//    getch();
    return (0);
}


void sortarray(int *arr, int num)
{
    int i,j,temp;
    for(i=0;i<num;i++)
        for(j=i+1;j<num;j++)
            if(arr[i] > arr[j])
            {
                temp=arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
