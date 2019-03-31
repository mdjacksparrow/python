
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Phonebook_Contacts //
{
    char FirstName[20];
    char LastName[20];
    char PhoneNumber[20];
} phone;

void AddEntry(phone* );
void DeleteEntry(phone* );
void PrintEntry(phone* );
void SearchForNumber(phone * );

int counter = 0;
char FileName[256];
FILE *pRead;
FILE *pWrite;

int main ()
{
    phone *phonebook; //
    phonebook = (phone*) malloc(sizeof(phone)*100); //
    int iSelection = 0;
    if (phonebook == NULL)
    {
        printf("Out of Memory. The program will now exit");
        return 1;
    }
    else
    {
        do
        {
            printf("\n\t\t\tPhonebook Menu : ");
            printf("\n\n\t(1)\tAdd Friend : ");
            printf("\n\t(2)\tDelete Friend : ");
            printf("\n\t(3)\tDisplay Phonebook Entries : ");
            printf("\n\t(4)\tSearch for Phone Number : ");
            printf("\n\t(5)\tExit Phonebook : ");
            printf("\n\nWhat would you like to do? ");
            scanf("%d", &iSelection);

            switch(iSelection)
            {
                case 1:	AddEntry(phonebook); break;
                case 2: DeleteEntry(phonebook); break;
                case 3: PrintEntry(phonebook); break;
                case 4: SearchForNumber(phonebook); break;
                case 5: printf("\nYou have chhosen to exit the Phonebook.\n");
                        exit (0);
            }
        } while (iSelection <= 4);
    }

}
void AddEntry (phone *phonebook)
{
    pWrite = fopen("phonebook_contacts.dat", "a");
    if ( pWrite == NULL )
    {
        perror("The following error occurred ");
        exit(EXIT_FAILURE);
    }
    else
    {
        counter++;
        phonebook = realloc(phonebook, sizeof(phone));
        printf("\nFirst Name: ");
        scanf("%s", phonebook[counter-1].FirstName);
        printf("Last Name: ");
        scanf("%s", phonebook[counter-1].LastName);
        printf("Phone Number (XXX-XXX-XXXX): ");
        scanf("%s", phonebook[counter-1].PhoneNumber);
        printf("\n\tFriend successfully added to Phonebook\n"); 			     fprintf(pWrite,"%s\t%s\t%s\n",phonebook[counter-1].FirstName,phonebook[counter-1].LastName, phonebook[counter-1].PhoneNumber);
        fclose(pWrite);
    }
}
void DeleteEntry (phone * phonebook)
{
    int x = 0; int i = 0;
    char deleteFirstName[20]; //
    char deleteLastName[20];
    printf("\nFirst name: ");
    scanf("%s", deleteFirstName);
    printf("Last name: ");
    scanf("%s", deleteLastName);
    for (x = 0; x < counter; x++)
    {
        if (strcmp(deleteFirstName, phonebook[x].FirstName) == 0)
        {
            if (strcmp(deleteLastName, phonebook[x].LastName) == 0)
            {
                for ( i = x; i < counter - 1; i++ )
                {
                    strcpy(phonebook[i].FirstName, phonebook[i+1].FirstName);
                    strcpy(phonebook[i].LastName, phonebook[i+1].LastName);
                    strcpy(phonebook[i].PhoneNumber, phonebook[i+1].PhoneNumber);
                }
                printf("Record deleted from the phonebook.\n\n");
                --counter;
                return;
            }
        }
    }
    printf("That contact was not found, please try again.");
}
void PrintEntry (phone * phonebook)
{
    int x = 0;
    printf("\nPhonebook Entries:\n\n ");
    pRead = fopen("phonebook_contacts.dat", "r");
    if ( pRead == NULL)
    {
        perror("The following error occurred: ");
        exit(EXIT_FAILURE);
    }
    else
    {
        for( x = 0; x < counter; x++)
        {
            printf("\n(%d)\n", x+1);
            printf("Name: %s %s\n", phonebook[x].FirstName, phonebook[x].LastName);
            printf("Number: %s\n", phonebook[x].PhoneNumber);
        }
    }
    fclose(pRead);
}
void SearchForNumber (phone * phonebook)
{
    int x = 0;
    char TempFirstName[20];
    char TempLastName[20];
    printf("\nPlease type the name of the friend you wish to find a number for.");
    printf("\n\nFirst Name: ");
    scanf("%s", TempFirstName);
    printf("Last Name: ");
    scanf("%s", TempLastName);
    for (x = 0; x < counter; x++)
    {
        if (strcmp(TempFirstName, phonebook[x].FirstName) == 0)
        {
            if (strcmp(TempLastName, phonebook[x].LastName) == 0)
            {
                printf("\n%s %s's phone number is %s\n", phonebook[x].FirstName, phonebook[x].LastName, phonebook[x].PhoneNumber);
            }
        }
    }
}

