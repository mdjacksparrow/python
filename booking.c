//
// Created by jack on 15/3/19.
//

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int first = 5,second = 5,thired = 5;
struct node
{
    int ticketno;
    int phoneno;
    char name[30];
    char address[50];
}s[15]; // the array of structures of type node is declared

int i=0;
void booking() // passenger details are accepted
{
    printf("enter your details\n");
    printf("\nname:");
    scanf("%s",s[i].name);
    printf("\nphonenumber:");
    scanf("%d",&s[i].phoneno);
    printf("\naddress:");
    scanf("%s",s[i].address);
    printf("\nticketnumber only 1-10:");
    scanf("%d",&s[i].ticketno);
    i++;
}
 

void availability()
{
    int c;
    printf("availability cheking");
    printf("\n1.first class\n2.second class\n3.third class\n");
    printf("enter the option");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            if(first>0)
            {
                printf("seat available\n");
                first--;     // after checking the availability of 1st class seats, 1 seat is allocated and 			//avail no of 1st class seats is decremented
            }
            else
            {
                printf("seat not available");
            }
            break;
        case 2:
            if(second > 0)
            {
                printf("seat available\n");
                second--;
            }
            else
            {
                printf("seat not available");
            }
            break;
        case 3:
            if(thired > 0)
            {
                printf("seat available\n");
                thired--;
            }
            else
            {
                printf("seat not available");
            }
            break;
        default:
            break;
    }
}
void cancel()
{
    int c;
    printf("cancel\n");
    printf("which class you want to cancel");
    printf("\n1.first class\n2.second class\n3.thired class\n");
    printf("enter the option");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            first++; // after cancellation of 1st class ticket avail no of 1st class tickets/seats is 			//incremented
            break;
        case 2:
            second++;
            break;
        case 3:
            thired++;
            break;
        default:
            break;
    }
    printf("ticket is canceled");
}
void chart()
{
    int c , I = 15;
    for(c = 0;c < I; c++)
    {
        printf("\n Ticket No :\t Name :\n");
        printf("\t%d\t%s\n",s[c].ticketno,s[c].name);
    }
}


int main()
{
    int n;

    ///clrscr();  it is a predefined fn in conio.h, used to clear the monitor

    printf("welcome to railway ticket reservation\n");
    while(1) {
        printf("1.booking\n2.availability cheking\n3.cancel\n4.Chart \n5. Exit\nenter your option:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: booking();/* <-- booking fn is called*/ break;
            case 2: availability(); break;
            case 3: cancel(); break;
            case 4: chart(); break;
            case 5: printf("\n Thank you visit again!");exit(0); // indicates successful program termination
            default: break;
        }
    }
    return 0;
}

