#include<stdio.h>
//#include<conio.h>

struct stud                 //stud structure
{
    char name[20];
    long int rollno;		//use 'long' keyword for increase the memory bytes
    int marks[5][3];             // use multi-D array for store marks of each students
    int avg[5];			// i{ 0 - 4 }
} students[10];      //students variable contain maximum 10 stud {0 - 9}


void calcinternal(int);


int main()
{
    int a, b, j, n;                        //to declared variables of the program
//    clrscr();
    printf("How many students : \n");
    scanf("%d", &n);                     //to store the no of stud in 'n' variable
    for (a = 0; a < n; ++a)                    //to get stud data through the loop
    {
//        clrscr();
        printf("\n\nEnter the details of %d student : ", a + 1);
        printf("\n\nEnter student %d Name : ", a + 1);
        scanf("%s", students[a].name);
        printf("\n\nEnter student %d Roll Number : ", a + 1);
        scanf("%ld", &students[a].rollno);
        for (b = 0; b <= 4; ++b) {
            for (j = 0; j <= 2; ++j) {
                printf("\n\nEnter the test %d mark of subject-%d : ", j + 1, b + 1);
                scanf("%d", &students[a].marks[b][j]);            //to store mark in multi dimentional array
            }
        }
    }


    calcinternal(n);                    //To call the calcinternal function


    for (a = 0; a < n; ++a)
    {
///        clrscr();
        printf("\n\n\t\t\t\tMark Sheet\n");
        printf("\nName of Student : %s", students[a].name);
        printf("\t\t\t\t Roll No : %ld", students[a].rollno);
        printf("\n------------------------------------------------------------------------");
        for (b = 0; b < 5; b++)
        {
            printf("\n\n\t Subject %d internal \t\t :\t %d", b + 1, students[a].avg[b]);
        }
        printf("\n\n------------------------------------------------------------------------\n");
    }
    return (0);
}


void calcinternal(int n)            //to calculate internal marks of eash student
{
    int a, b, j, total;
    for (a = 0; a < n; ++a) 
    {
        for (b = 0; b < 5; b++) 
	{
            total = 0;
            for (j = 0; j <= 2; ++j) 
	    {
                total += students[a].marks[b][j];
            }
            students[a].avg[b] = total / 3;
        }
    }
}

