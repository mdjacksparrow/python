/*
5 if it is a perfect cube	nArray = {11,8,24}   --->    ans = [ 3 5 4 ]
4 if it is a multiple of 4 and divisabel by 6
3 if it is a prime number
sort the array of weights
*/ 


#include <stdio.h>

int prime(int);
int swap(int *,int *);
int sort(int*,int);

void main() 
{ 
 int nArray[10],wArray[10]={0},nelem = 3,i,j,k,flag=0; 
 printf("\n Enter the number of elements in an array : "); 
 scanf("%d",&nelem);
 printf("\n You are enter %d elements\n",nelem);
 
 for(i=0;i<nelem;i++) 
	 scanf("%d",&nArray[i]);			//Enter the element are one by one....");
 
 for (j=0;j<nelem;j++)
{
//to check perfect cube for this loop
 for(i=2;i <= nArray[j]/2;i++){
	if((i*i*i) == nArray[j])
	{
	 wArray[j] = wArray[j] +5; 
	 break;
	}
    } 
 if (((nArray[j]*4)%6) == 0)
	wArray[j] =wArray[j] + 4;
 
 flag = prime(nArray[j]);
 
 if (flag != 1)
	wArray[j] = wArray[j] +3;
}

sort(wArray,nelem);

printf("The sort weights of given array is below...\n");
for (k=0;k<nelem;++k)
{
	printf("%d\n",wArray[k]);
}
}
	
//function for checking prime number

int prime(int num)
{
int i,flag = 0;
for (i=2;i<=num/2;i++)
{
	//condition for nonprime number
	if(num%i == 0){
		flag = 1;
		break;
		}
}
return flag;
}

//This function is used to swap the two variables in the given array which is used by sort function

int swap(int *x,int *y)
{
int temp = *x;
*x = *y;
*y = temp;
return 0;
}

//This function is sorting purpose for manipulate the weighting array

int sort(int arr[],int n)
{
int i,j,min;
for (i = 0;i<n-1;i++)
{
	min = i;
	for (j = i+1;j<n;j++)
	{
		if(arr[j] < arr[min])
			min = j;
	}
	swap(&arr[min],&arr[i]);
}
return *arr;
}
