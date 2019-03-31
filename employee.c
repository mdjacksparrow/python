#include<stdio.h>
//#include<conio.h>
#include "stdlib.h"


struct emp
{
    int empno ;
    char name[10], answer ;
    int bpay, allow, ded, npay ;

    struct emp *next;
} e;


int main()
{
    int i , n = 0;
    char answer;
    int more_data = 1;
    struct emp *current_ptr, *head_ptr;
//    clrscr() ;
    head_ptr = (struct emp*) malloc (sizeof(struct emp));
    current_ptr = head_ptr;
    
    while (more_data)
    {
        {
            printf("\nEnter the employee number : ") ;
            scanf("%d", &current_ptr -> empno) ;
            printf("\nEnter the name : ") ;
            scanf("%s", current_ptr -> name) ;
            printf("\nEnter the basic pay \t:\t");
	    scanf("%d",&current_ptr -> bpay);
            printf("\nEnter the Allowvence \t:\t");
	    scanf("%d",&current_ptr -> allow);
	    printf("\nEnter the Deduction \t:\t");
	    scanf("%d",&current_ptr -> ded);
            current_ptr -> npay = current_ptr -> bpay + current_ptr -> allow - current_ptr->ded ;
            n++;
            printf("Would you like to add another employee? (y/n): ");
            scanf("%s", &answer);
            if (answer != 'y')
            {
                current_ptr -> next = (struct emp*)NULL;
                more_data = 0;
            }
            else 
            {
                current_ptr -> next = (struct emp*) malloc(sizeof(struct emp));
                current_ptr = current_ptr -> next;
            }
        }
    }
    
    printf("\nEmp. No. Name \t Bpay \t Allow \t Ded \t Npay \n\n") ;
    current_ptr = head_ptr;
    for(i = 0 ; i < n ; i++)
    {
        printf("%d \t %s \t %d \t %d \t %d \t %d \n", current_ptr -> empno,
               current_ptr -> name, current_ptr -> bpay, current_ptr -> allow, current_ptr -> ded,
               current_ptr -> npay) ;
        current_ptr = current_ptr -> next;
    }
    return (0);
} 
